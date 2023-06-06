/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node* head = new Node(0),*temp=head;

    int carry=0;

    while(num1&&num2)
    {
        int s = (num1->data+num2->data+carry);

        num1= num1->next;
        num2= num2->next;

        temp->next = new Node(s%10);
        temp=temp->next;
        carry = s/10;
    }
    while(num1)
    {
        int s = (num1->data+carry);
        num1= num1->next;
        temp->next = new Node(s%10);
        temp = temp->next;
        carry = s/10;
    }
    while(num2)
    {
        int s = (num2->data+carry);
        num2= num2->next;
        temp->next = new Node(s%10);
        temp = temp->next;
        carry = s/10;
    }
    if(carry) temp->next = new Node(carry);

    return head->next;

}
