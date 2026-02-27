#include<iostream>
using namespace std;

struct Queue {
    int arr[100];
    int front, rear;

    Queue() {
        front = rear = 0;
    }

    void insert(int value) {
        if (rear == 100) {
            cout << "Overflow" << endl;
            return;
        }
        arr[rear++] = value;
    }

    void delette() {
        if (front == rear) {
            cout << "Underflow" << endl;
            return;
        }
        front++;
    }

    void display() {
        if (front == rear) {
            cout << "Queue empty" << endl;
            return;
        }
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.insert(1);
    q.insert(2);
    q.insert(3);
    q.delette();
    q.display();
}
