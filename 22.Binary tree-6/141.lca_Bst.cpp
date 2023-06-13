#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

bool isleft(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
    if(p->data < root->data && q->data < root->data)
    {
        return true;
    }
    return false;
}

bool isright(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
    if(p->data > root->data && q->data > root->data)
    {
        return true;
    }
    return false;
}

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	// Write your code here

    TreeNode<int>* temp = root;

    while(true)
    {
        //cout<<temp->data<<" "<<isright(root,p,q)<<endl;
        if(isleft(temp,p,q))
            temp = temp->left;
        else 
            if(isright(temp,p,q))
                temp = temp->right; 
        else 
            return temp;
    }
    return temp;
}
