#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class sll {
    Node* head;
    Node* tail;

public:
    sll() {
        head = tail = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteNode() {
        if (!head) {
            cout << "SLL is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = NULL;
    }

    void display() {
        if (!head) {
            cout << "SLL is empty" << endl;
            return;
        }
        cout << "SLL: ";
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    sll s;
    s.insert(5);
    s.insert(10);
    s.insert(15);
    s.deleteNode();
    s.display();
}
