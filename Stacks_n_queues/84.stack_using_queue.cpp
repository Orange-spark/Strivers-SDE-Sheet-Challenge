#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    
   vector<int> q;
   int start,end;
   public:
    Stack() {
      start =0,end=0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
    
        return q.size()==0;
    }

    void push(int element) {
        // Implement the push() function.
        q.push_back(element);
    }

    int pop() {
        if(isEmpty()) return -1;
        // Implement the pop() function.
        int x =q.back();
        q.pop_back();
        return x;
    }

    int top() {
        if(isEmpty()) return -1;
        // Implement the top() function.
        return q.back();
    }
};
