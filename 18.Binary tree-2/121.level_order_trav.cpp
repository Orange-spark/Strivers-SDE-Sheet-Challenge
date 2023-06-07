#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> ans;
    if(!root) return ans;

    queue<BinaryTreeNode<int> *>q;
    q.push(root);

    while(!q.empty())
    {
        int n= q.size();

        for(int i=0;i<n;i++)
        {
            auto node =q.front();
            q.pop();

            ans.push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }

    return ans;
}
