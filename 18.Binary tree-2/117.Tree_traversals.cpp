#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int> inorder,preorder,postorder;
    if(!root) return {inorder,preorder,postorder};

    stack<pair<BinaryTreeNode<int>*,int>> st;

    st.push({root,0});

    while(!st.empty())
    {
        auto node = st.top().first ;
        int n = st.top().second;
        st.pop();

        if(n==0)
        {
            preorder.push_back(node->data);
            st.push({node,n+1});
            if(node->left) st.push({node->left,0});
        }
        else if(n==1)
        {
            inorder.push_back(node->data);
            st.push({node,n+1});
            if(node->right) st.push({node->right,0});
        }
        else{
            postorder.push_back(node->data);
        }
    }
    return {inorder,preorder,postorder};
}
