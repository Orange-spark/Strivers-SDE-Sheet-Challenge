#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return root;

    TreeNode<int> * r =flattenBinaryTree(root->right);
    TreeNode<int> * l = flattenBinaryTree(root->left);

    if(l)
    {
        root->left = NULL;
        TreeNode<int> *temp =l;
        while(temp->right) temp = temp->right;

        temp->right =r;

        root->right =l;
    }

    return root;
}
