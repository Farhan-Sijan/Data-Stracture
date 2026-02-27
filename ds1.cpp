#include<iostream>
using namespace std;

class Stack {
    int arr[100];  
    int top;

public:
    Stack() {
        top = -1;
    }

    void insert(int value) {
        if (top < 99) {  
            arr[top++] = value;
        } else {
            cout << "Over" << endl;
        }
    }

    void deleteNode() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Underflow" << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.insert(12);
    s.insert(24);
    s.insert(85);
    s.deleteNode();
    s.display();
}
