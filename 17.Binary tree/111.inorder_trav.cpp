#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> inorder;
    TreeNode* temp =root;
    stack<TreeNode*> st;

    while(true)
    {
        if(temp)
        {
            st.push(temp);
            temp=temp->left;
        }
        else{
            if(st.empty()) break;
            auto node = st.top();
            st.pop();
            inorder.push_back(node->data);

            temp =node->right;
        }
    }
    return inorder;
}
