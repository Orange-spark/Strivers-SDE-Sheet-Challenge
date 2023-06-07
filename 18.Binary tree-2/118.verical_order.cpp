#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    if(!root) return ans;

    queue<pair<int,pair<TreeNode<int> *,int>>> q;

    q.push({0,{root,0}});

    map<int,map<int,vector<int>>> mp;

    while(!q.empty())
    {
        auto line = q.front().first;
        auto node = q.front().second.first;
        auto level = q.front().second.second;
        q.pop();

        mp[line][level].push_back(node->data);

        if(node->left) q.push({line-1,{node->left,level+1}});
        if(node->right) q.push({line+1,{node->right,level+1}});
    }

    for(auto line:mp)
    {
        for(auto level:line.second)
        {
            for(auto val : level.second)
            {
                ans.push_back(val);
            }
        }
    }
    return ans;
}
