#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* buildBST(vector<int> &preorder, int &index, int ub = INT_MAX){
    // Recursive Approach
    // Time Complexity: O(N)
    // Space Complexity: O(Height)
    // Base case
    if(preorder.size() <= index || preorder[index] >= ub) return NULL;
    // Build Root
    TreeNode<int>* root = new TreeNode<int>(preorder[index]);
    index++; 
    root->left = buildBST(preorder, index, root->data);
    root->right = buildBST(preorder, index, ub);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Recursive Approach
    int index = 0;
    return buildBST(preOrder, index); 
}
