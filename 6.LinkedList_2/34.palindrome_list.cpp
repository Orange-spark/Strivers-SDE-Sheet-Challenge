#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.

    LinkedListNode<int> *slow,*fast;

    slow=fast = head;
    int n=0;

    while(fast && fast->next)
    {
        n++;
        slow =slow->next;

        fast = fast->next->next;
    }    

    LinkedListNode<int> *prev=NULL,*nex,*cur =slow;

    while(cur)
    {
        nex = cur->next;
        cur->next = prev;
        prev =cur;
        cur = nex;
    }

    slow = head;
    while(prev)
    {
        if(slow->data!=prev->data) return false;
        slow =slow->next;
        prev = prev->next;
        
    }

    return true;
}
