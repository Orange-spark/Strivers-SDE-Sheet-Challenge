#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ceil =-1;

    BinaryTreeNode<int> *temp = node;

    while(temp)
    {
        int  y=temp->data;
        if(y>=x)
        {
            ceil = y;
            temp = temp->left;
        }
        else{
            temp=temp->right;
        }
    }

    return ceil;
}
