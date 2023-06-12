#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* get_tree(int in1,int in2,int pre1,int pre2,
vector<int> &preorder, vector<int> &inorder,unordered_map<int,int> &index)
{
    /*Write a terminating condition*/
    if(in1>in2 or pre1>pre2)
    {
        return NULL;
    }

    TreeNode<int> *root = new TreeNode<int>(preorder[pre1]);

    int r =  index[root->data];
    int size  =  r-in1;

    root->left = get_tree(in1,r-1,pre1+1,pre1+size,preorder,inorder,index);
    root->right = get_tree(r+1,in2,pre1+size+1,pre2,preorder,inorder,index);   

    //cout<<root->data<<" ";

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    unordered_map<int,int> index;

    for(int i=0;i<inorder.size();i++)
    {
        index[inorder[i]]=i;
    }

    int n =preorder.size();
    TreeNode<int> *root = get_tree(0,n-1,0,n-1,preorder,inorder,index);

    return root;
}
