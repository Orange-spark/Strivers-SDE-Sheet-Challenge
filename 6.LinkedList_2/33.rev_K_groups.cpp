#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	Node* temp,*d=new Node(0),*cur,*prev,*nex,*tail=d;

	temp =d;

	cur = head;
	int k=0;
	temp->next =cur;
	prev=NULL;
	while(k<n&&cur)
	{	//cout<<k<<" ";
		if(b[k]==0){
			k++;
			continue;
		}
		prev=NULL;
		tail = cur;
		while(b[k]&&cur)
		{	
			nex =cur->next;
			cur->next =prev;
			prev= cur;
			cur = nex;
			b[k]--;
		}
		k++;
		temp->next =prev; 
		temp =tail;
		// cout<<"temp_list";
		// printlist(d->next);
		// cout<<"rem_list";
		// printlist(cur);
	}
	if(k>=n&&cur)
	{
		tail->next =cur;
	}
	// cout<<"exited";
	// printlist(d->next);
	return d->next;
}
