#include<iostream>
using namespace std;

class DLLNode {
public:
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int val) {
        data = val;
        prev = next = NULL;
    }
};

class DLLManager {
    DLLNode* head;
    DLLNode* tail;

public:
    DLLManager() {
        head = tail = NULL;
    }

    void push_front(int val) {
        DLLNode* newNode = new DLLNode(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_back() {
        if (head == NULL) {
            cout << "DLL is empty" << endl;
            return; 
        }

        DLLNode* temp = tail;

        if (head == tail) {  
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
    }

    void display() {
        if (!head) {
            cout << "DLL is empty" << endl;
            return;
        }
        cout << "DLL: ";
        DLLNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DLLManager dll;
    dll.push_front(7);
    dll.push_front(8);
    dll.push_front(9);
    dll.pop_back();
    dll.display(); 
}
