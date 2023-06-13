#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int pre=-1,suc=-1;
    BinaryTreeNode<int>* temp=root;
    
    while(temp)
    {
        int x =temp->data;
        if(x>key)
        {
            suc = x;
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    temp = root;
    while(temp)
    {
        int x =temp->data;
        if(x<key)
        {
            pre = x;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    
    return {pre,suc};
}
