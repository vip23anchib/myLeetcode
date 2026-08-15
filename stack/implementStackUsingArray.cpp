#include <bits/stdc++.h>
using namespace std;

class Stack {

    int arr[1000];   // stores stack elements
    int top;         // index of top element

public:

    // Constructor
    Stack() {
        top = -1;    // stack initially empty
    }

    // Add element
    void push(int x) {

        if (top == 999) {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = x;
    }

    // Remove top element
    int pop() {

        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }

        return arr[top--];
    }

    // See top element
    int peek() {

        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }

        return arr[top];
    }

    // Check whether empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {

    Stack st;

    st.push(5);
    st.push(10);
    st.push(20);

    cout << st.peek() << endl;     // 20

    cout << st.pop() << endl;      // 20
    cout << st.pop() << endl;      // 10

    cout << st.peek() << endl;     // 5

    return 0;
}
