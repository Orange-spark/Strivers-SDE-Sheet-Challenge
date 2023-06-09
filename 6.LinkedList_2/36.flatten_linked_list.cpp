/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

void print_list(Node* head)
{
	Node* temp =head;
	cout<<endl;
	while(temp)
	{
		cout<<temp->data<<"->";
		temp =temp->child;
	}
	cout<<endl;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here

	Node* d = new Node(0);

	Node* iterator = head->next;

	d->child = head;

	

	while(iterator)
	{
		Node* temp = d;

		Node* temp1 = d->child,*temp2 =iterator;

		iterator = iterator->next;

		temp1->next = temp2->next =NULL; 

		while(temp1&&temp2)
		{
			if(temp1->data<temp2->data)
			{
				temp->child =  temp1;
				temp1 = temp1->child;
			}
			else{
				temp->child =  temp2;
				temp2 = temp2->child;
			}
			temp = temp->child;
			//cout<<temp->data<<"->";
		}
		if(temp1)
		{
			temp->child = temp1;
		}
		else
		    temp->child = temp2;

		//cout<<endl;
		//print_list(d->next);
			
	}
	return d->child;
}
