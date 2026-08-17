#include <bits/stdc++.h>
using namespace std;

class Queue {

    int arr[1000];
    int start;
    int end;
    int currSize;

public:

    // Constructor
    Queue() {
        start = -1;
        end = -1;
        currSize = 0;
    }

    // Add element to queue
    void push(int x) {

        // Queue is full
        if (currSize == 1000) {
            cout << "Queue is full\n";
            return;
        }

        // First element
        if (start == -1) {
            start = 0;
            end = 0;
        }
        else {
            end++;
        }

        arr[end] = x;
        currSize++;
    }

    // Remove front element
    int pop() {

        // Queue is empty
        if (currSize == 0) {
            cout << "Queue is empty\n";
            return -1;
        }

        int x = arr[start];

        // If this was the last element
        if (currSize == 1) {
            start = -1;
            end = -1;
        }
        else {
            start++;
        }

        currSize--;

        return x;
    }

    // Return front element
    int peek() {

        if (currSize == 0) {
            cout << "Queue is empty\n";
            return -1;
        }

        return arr[start];
    }

    // Check if queue is empty
    bool isEmpty() {
        return currSize == 0;
    }
};


int main() {

    Queue q;

    q.push(5);
    q.push(10);
    q.push(20);

    cout << q.peek() << endl;      // 5

    cout << q.pop() << endl;       // 5
    cout << q.pop() << endl;       // 10

    cout << q.peek() << endl;      // 20

    cout << q.isEmpty() << endl;   // 0

    return 0;
}
