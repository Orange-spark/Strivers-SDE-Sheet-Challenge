#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.

    Node<int>* d,*t1=first,*t2=second,*temp;

    d = new Node<int>(0);
    temp = d;

    while(t1&&t2)
    {
        if(t1->data<t2->data)
        {
            temp->next= t1;
            temp =t1;
            t1 = t1->next; 
        }
        else{
            temp->next= t2;
            temp =t2;
            t2 = t2->next; 
        }
    }
    while(t1)
    {
        temp->next= t1;
        temp =t1;
        t1 = t1->next;    
    }
    while(t2)
    {
        temp->next= t2;
        temp =t2;
        t2 = t2->next;    
    }
    
return d->next;
}
