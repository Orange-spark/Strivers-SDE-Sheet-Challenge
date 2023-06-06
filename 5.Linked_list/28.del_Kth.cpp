/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int n=0;
    Node* temp=head;

    while(temp)
    {
        n++;
        temp=temp->next;
    }

    int loc = n-K+1;

    if(loc==1) return head->next;

    temp=head;

    for(int i=1;i<loc-1;i++)
    {
        temp = temp->next;
    }
    //cout<<temp->data<<endl;
    if(temp->next)
        temp->next = temp->next->next;
    else 
        temp->next = NULL;

    return head;
}
