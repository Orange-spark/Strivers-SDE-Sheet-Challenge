#include<bits/stdc++.h>

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* get_tree(int in1,int in2,int post1,int post2,
vector<int>& postorder, vector<int>& inorder,unordered_map<int,int> &index)
{
     if(in1>in2 or post1>post2)
          return NULL;

     TreeNode<int> *root = new TreeNode<int> (postorder[post2]);

     int r = index[root->data];
     int size = r-in1;

     root->left = get_tree(in1,r-1,post1,post1+size-1,postorder,inorder,index);
     root->right = get_tree(r+1,in2,post1+size,post2-1,postorder,inorder,index);

     return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     int n=postOrder.size();

     unordered_map<int,int> index;
     for(int i=0;i<n;i++)
     {
          index[inOrder[i]]=i;
     }

     TreeNode<int> *root = get_tree(0,n-1,0,n-1,postOrder,inOrder,index);

     return root;
}
