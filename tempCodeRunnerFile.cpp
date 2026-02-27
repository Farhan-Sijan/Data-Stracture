#include <iostream>
#include <string>

using namespace std;

// Visa types
const string visaTypes[] = {"TR", "MED", "BS", "GO"};
const string visaTypeNames[] = {
    "Tourist Visa", 
    "Medical Visa", 
    "Business Visa", 
    "Government Officials Visa"
};

// Structure to hold applicant information
struct Applicant {
    int tokenNumber;
    int visaType; // 0-TR, 1-MED, 2-BS, 3-GO
    string tokenString;
};

// Maximum queue size for each visa type
const int MAX_QUEUE_SIZE = 25;

// Embassy system class
class EmbassySystem {
private:
    Applicant queues[4][MAX_QUEUE_SIZE]; // 4 visa types, each with max 25 applicants
    int queueFront[4] = {0}; // Front pointer for each queue
    int queueRear[4] = {0};  // Rear pointer for each queue
    int nextTokenNumber = 1;
    int visaCounters[4] = {0}; // Count of applicants per visa type
    int counterStats[4][4] = {0}; // [counter][visaType] count
    int totalApplicantsServed = 0;

    // Helper function to check if a queue is empty
    bool isQueueEmpty(int visaType) {
        return queueFront[visaType] == queueRear[visaType];
    }

    // Helper function to check if a queue is full
    bool isQueueFull(int visaType) {
        return visaCounters[visaType] >= MAX_QUEUE_SIZE;
    }

    // Helper function to get the size of a queue
    int getQueueSize(int visaType) {
        return queueRear[visaType] - queueFront[visaType];
    }

    // Helper function to find the longest non-empty queue (excluding the specified one)
    int findLongestQueue(int excludeVisaType) {
        int maxSize = -1;
        int longestQueue = -1;

        for (int i = 0; i < 4; i++) {
            if (i != excludeVisaType && !isQueueEmpty(i)) {
                int size = getQueueSize(i);
                if (size > maxSize) {
                    maxSize = size;
                    longestQueue = i;
                }
            }
        }

        return longestQueue;
    }

public:
    EmbassySystem() {
        // Initialize all counters to 0
        for (int i = 0; i < 4; i++) {
            visaCounters[i] = 0;
            queueFront[i] = 0;
            queueRear[i] = 0;
            for (int j = 0; j < 4; j++) {
                counterStats[i][j] = 0;
            }
        }
    }

    // Function to request a token
    void requestToken(const string& visaTypeName) {
        int visaType = -1;
        for (int i = 0; i < 4; i++) {
            if (visaTypeNames[i] == visaTypeName) {
                visaType = i;
                break;
            }
        }

        if (visaType == -1) {
            cout << "Invalid visa type!" << endl;
            return;
        }

        if (isQueueFull(visaType)) {
            cout << "Daily limit reached for " << visaTypeName << ". No more tokens can be issued today." << endl;
            return;
        }

        string tokenStr = visaTypes[visaType] + "-" + to_string(nextTokenNumber);
        cout << "Your token is: " << tokenStr << endl;

        Applicant applicant;
        applicant.tokenNumber = nextTokenNumber;
        applicant.visaType = visaType;
        applicant.tokenString = tokenStr;

        queues[visaType][queueRear[visaType] % MAX_QUEUE_SIZE] = applicant;
        queueRear[visaType]++;
        visaCounters[visaType]++;
        nextTokenNumber++;
    }

    // Function to call the next customer
    void callNextCustomer(int counter) {
        int primaryVisaType = counter - 1; // Counter 1: TR (0), Counter 2: MED (1), etc.

        // First try primary queue
        if (!isQueueEmpty(primaryVisaType)) {
            Applicant next = queues[primaryVisaType][queueFront[primaryVisaType] % MAX_QUEUE_SIZE];
            queueFront[primaryVisaType]++;
            cout << "Counter " << counter << ", Please serve the token number \"" << next.tokenString << "\"" << endl;

            // Update stats
            counterStats[counter-1][primaryVisaType]++;
            totalApplicantsServed++;
            return;
        }

        // If primary queue is empty, find the longest other queue
        int longestQueue = findLongestQueue(primaryVisaType);
        if (longestQueue != -1) {
            Applicant next = queues[longestQueue][queueFront[longestQueue] % MAX_QUEUE_SIZE];
            queueFront[longestQueue]++;
            cout << "Counter " << counter << ", Please serve the token number \"" << next.tokenString << "\"" << endl;

            // Update stats
            counterStats[counter-1][longestQueue]++;
            totalApplicantsServed++;
            return;
        }

        // All queues are empty
        cout << "Counter " << counter << " is idle. No applicants to serve." << endl;
    }

    // Function to generate daily summary
    void generateDailySummary() {
        cout << "\n=== Daily Summary Report ===\n";
        
        // 1. Applicants served by Visa Type
        cout << "1. Applicants served by Visa Type:\n";
        int visaTypeTotals[4] = {0};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                visaTypeTotals[j] += counterStats[i][j];
            }
        }
        
        for (int i = 0; i < 4; i++) {
            cout << "- " << visaTypes[i] << ": " << visaTypeTotals[i] << "\n";
        }
        
        // 2. Applicants served by Counter
        cout << "\n2. Applicants served by Counter:\n";
        for (int i = 0; i < 4; i++) {
            cout << "- Counter " << (i+1) << " (" << visaTypes[i] << "): ";
            bool first = true;
            for (int j = 0; j < 4; j++) {
                if (counterStats[i][j] > 0) {
                    if (!first) cout << ", ";
                    cout << visaTypes[j] << ": " << counterStats[i][j];
                    first = false;
                }
            }
            cout << "\n";
        }
        
        // 3. Idle Counters
        cout << "\n3. Idle Counters:\n";
        bool anyIdle = false;
        for (int i = 0; i < 4; i++) {
            bool isIdle = true;
            for (int j = 0; j < 4; j++) {
                if (counterStats[i][j] > 0) {
                    isIdle = false;
                    break;
                }
            }
            if (isIdle) {
                cout << "- " << visaTypes[i] << "\n";
                anyIdle = true;
            }
        }
        if (!anyIdle) {
            cout << "- None\n";
        }
        
        cout << "\nTotal Applicants Served: " << totalApplicantsServed << endl;
    }
};

int main() {
    EmbassySystem embassy;
    int choice;
    
    do {
        cout << "\nEmbassy Consulate Service System\n";
        cout << "1. Request Token\n";
        cout << "2. Call Next Customer\n";
        cout << "3. Generate Daily Summary\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                cout << "Enter visa type (Tourist Visa, Medical Visa, Business Visa, Government Officials Visa): ";
                string visaType;
                cin.ignore();
                getline(cin, visaType);
                embassy.requestToken(visaType);
                break;
            }
            case 2: {
                cout << "Enter counter number (1-4): ";
                int counter;
                cin >> counter;
                if (counter >= 1 && counter <= 4) {
                    embassy.callNextCustomer(counter);
                } else {
                    cout << "Invalid counter number!" << endl;
                }
                break;
            }
            case 3:
                embassy.generateDailySummary();
                break;
            case 4:
                cout << "Exiting system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
    
    return 0;
}