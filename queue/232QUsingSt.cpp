

class MyQueue {
private:
    stack<int> in;
    stack<int> out;

public:
    MyQueue() {
        
    }

    void push(int x) {
        
        in.push(x);
    }

    int pop() {
        
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

       
        int ans = out.top();
        out.pop();

        return ans;
    }

    int peek() {
       
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        
        return out.top();
    }

    bool empty() {
        // Queue is empty only if BOTH stacks are empty
        return in.empty() && out.empty();
    }
};
