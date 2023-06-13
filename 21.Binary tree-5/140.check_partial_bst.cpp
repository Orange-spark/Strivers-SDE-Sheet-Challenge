#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool validate(BinaryTreeNode<int> *root,int &lb,int &up)
{
    if(!root) return true;

    if(root->data>up or root->data<lb) return false;

    bool left = validate(root->left,lb,root->data);
    bool right = validate(root->right,root->data,up);

    return left&&right;
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    int lb=INT_MIN;
    int up =INT_MAX;

    return validate(root,lb,up);
}
