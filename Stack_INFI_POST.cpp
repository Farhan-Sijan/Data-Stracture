#include<iostream>
using namespace std;

struct stack {
    char arr[100];
    int top;

    stack() {
        top = -1;
    }

    void push(char ch) {
        if (top >= 99) {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = ch;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }

    char peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            return 0;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int pre(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(string infix) {
    stack st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9')) {
            postfix += ch;
        } 
        else if (ch == '(') {
            st.top++;
            st.arr[st.top] = ch;
        } 
        else if (ch == ')') {
            while (st.top != -1 && st.arr[st.top] != '(') {
                postfix += st.arr[st.top];
                st.top--;
            }
            if (st.top != -1) 
           {
            st.top--; 
           }
        } 
        else if (isOperator(ch)) {
            while (st.top != -1 && pre(st.arr[st.top]) >= pre(ch)) {
                postfix += st.arr[st.top];
                st.top--;
            }
            st.top++;
            st.arr[st.top] = ch;
        }
    }

    while (st.top != -1) {
        postfix += st.arr[st.top];
        st.top--;
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
