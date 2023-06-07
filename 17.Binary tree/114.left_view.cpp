#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;

    if(!root) return ans;

    queue<pair<TreeNode<int>*,int>> q;

    q.push({root,0});

    map<int,int> mp;

    while(!q.empty())
    {
        auto node =q.front().first;
        int level = q.front().second;

        q.pop();

        if(mp.count(level)==0) mp[level] = node->data;

        if(node->left) q.push({node->left,level+1});
        if(node->right) q.push({node->right,level+1});
    }

    for(auto i:mp)
    {
        ans.push_back(i.second);
    }

    return ans;
}
