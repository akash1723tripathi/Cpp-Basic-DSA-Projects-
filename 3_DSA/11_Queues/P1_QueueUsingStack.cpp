class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    void moveInToOut() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) {
            moveInToOut();
        }
        int front = outStack.top();
        outStack.pop();
        return front;
    }

    int peek() {
        if (outStack.empty()) {
            moveInToOut();
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
