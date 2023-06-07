#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> ans;

    if(!root) return ans;

    queue<pair<BinaryTreeNode<int> *,int>> q;
    q.push({root, 0});

    map<int,int> mp;

    while(!q.empty())
    {
        auto node =q.front().first;
        int v_level = q.front().second;

        q.pop();

        mp[v_level] = node->data;

        if(node->left) q.push({node->left,v_level-1});
        if(node->right) q.push({node->right,v_level+1});
    }
    for(auto i:mp)
    {
        ans.push_back(i.second);
    }

    return ans;
}
