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

Node* findIntersection(Node *h1, Node *h2)
{
    //Write your code here
    Node* t1=h1,*t2=h2;

    while(t1!=t2)
    {
        if(t1==NULL) t2 = h1;
        if(t2==NULL) t1 = h2;
        
        t1=t1->next;
        t2=t2->next;

    }
return t1;
}
