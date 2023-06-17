#include<bits/stdc++.h>

class Queue {
    // Define the data members(if any) here.
    stack<int> s1,s2; 
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s2.push(val);

        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

    }

    int deQueue() {

        if(isEmpty()) return -1;
        // Implement the dequeue() function.
       int x = s1.top();
       s1.pop();

       return x;
    }

    int peek() {
        // Implement the peek() function here.

        if(isEmpty()) return -1;
        return s1.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.

        return s1.empty();
    }
};
