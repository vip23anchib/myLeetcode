#include <iosbits/stdc++.htream>
using namespace std;

// Function to convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> s;
    int n = postfix.size();

    // Traverse the postfix expression from left to right
    for (int i = 0; i < n; i++) {
        char c = postfix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            // Pop two operands from the stack
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();

            // Form the new infix expression and push back to stack
            s.push("(" + op1 + c + op2 + ")");
        }
    }

    // The final element in the stack is the result
    return s.top();
}

int main() {
    string postfix = "AB*C+";
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    return 0;
}
