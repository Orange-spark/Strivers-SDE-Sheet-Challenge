/****************************************************************

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


*****************************************************************/

Node *firstNode(Node *head)
{
    //    Write your code here.

    Node* slow ,*fast;
    slow =fast =head;

    while(fast&&fast->next)
    {
        fast =fast->next->next;
        slow =slow->next;

        if(slow==fast) break;
    }

    if(fast==NULL or fast->next==NULL) return NULL;

    slow = head;
    while(slow!=fast)
    {
        slow =slow->next;
        fast =fast->next;
    }

    return slow;
}
