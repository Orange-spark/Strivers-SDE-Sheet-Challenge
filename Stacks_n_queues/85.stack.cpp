#include <bits/stdc++.h> 
// Stack class.
class Stack {
    vector<int> st;
    int Top=-1;
    int size;
public:
    
    Stack(int capacity) {
        // Write your code here.
        st.resize(capacity);
        size=capacity;
    }

    void push(int num) {
        // Write your code here.
        st[++Top] =num;
    }

    int pop() {
        // Write your code here.
        if(isEmpty()) return -1;

        return st[Top--];
    }
    
    int top() {
        // Write your code here.
        if(isEmpty()) return -1;

        return st[Top];
    }
    
    int isEmpty() {
        // Write your code here.
    return Top==-1;
    }   
    
    int isFull() {
        // Write your code here.
    return Top==size-1;
    }
    
};
