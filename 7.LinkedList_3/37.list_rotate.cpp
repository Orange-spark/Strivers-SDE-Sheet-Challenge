/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.

     int n=0;
     Node* temp =head;
     while(temp)
     {
          n++;
          temp = temp->next;
     }

     k=k%n;
     if(k<1) return head;
     //cout<<k<<" ";
     temp =head;

     for(int i=0;i<n-k-1;i++)
     {
          temp = temp->next;
     }

     Node* temp2 = temp->next;
     temp->next = NULL;

     temp =temp2;
     while(temp->next)
     {
          temp=temp->next;
     }
     temp->next = head; 

     head =temp2;

     return head;
}
