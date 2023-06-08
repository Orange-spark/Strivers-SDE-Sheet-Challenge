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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if(!root) return ans;

    stack<BinaryTreeNode<int> *> st1,st2;
    st1.push(root);

    bool left =true;

    while(!st1.empty()or !st2.empty())
    {
        int n = left?st1.size():st2.size();

        for(int i=0;i<n;i++)
        {

            if(left)
            {
                auto node = st1.top();
                st1.pop();
                ans.push_back(node->data);
                if(node->left) st2.push(node->left);
                if(node->right) st2.push(node->right);
            }
            else{
                auto node = st2.top();
                st2.pop();
                ans.push_back(node->data);
                if(node->right) st1.push(node->right);
                if(node->left) st1.push(node->left);
            }
            
        }

        left = !left;
    }

    return ans;
}
