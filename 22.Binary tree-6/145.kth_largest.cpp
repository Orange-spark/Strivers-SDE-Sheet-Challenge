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
void solver(TreeNode<int>* root, int &k,int &num)
{
    if(!root or k==0) return;

    solver(root->right,k,num);
    k--;
    if(k==0) num = root->data;
    solver(root->left,k,num);

}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int num =-1;

    solver(root,k,num);

    return num;
}
