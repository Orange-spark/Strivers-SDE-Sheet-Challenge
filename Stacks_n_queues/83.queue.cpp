#include <bits/stdc++.h> 
class Queue {

    vector<int> q;
    int start,back;

public:
    Queue() {
        // Implement the Constructor
       start=0,back = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function

        if(start>back-1)
            return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        //cout<<start<<endl;
        q.push_back(data);
        back++;
        return;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty())
            return -1;
        return q[start++];
    }

    int front() {
        // Implement the front() function
        if(isEmpty())
            return -1;

        return q[start];
    }
};
