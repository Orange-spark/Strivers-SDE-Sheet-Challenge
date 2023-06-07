#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;

    if(!root) return ans;

    queue<pair<TreeNode<int> *,int>> q;
    q.push({root, 0});

    map<int,int> mp;

    while(!q.empty())
    {
        auto node =q.front().first;
        int v_level = q.front().second;

        q.pop();

        if(mp.count(v_level)==0)
            mp[v_level] = node->val;

        if(node->left) q.push({node->left,v_level-1});
        if(node->right) q.push({node->right,v_level+1});
    }
    for(auto i:mp)
    {
        ans.push_back(i.second);
    }

    return ans;

}
