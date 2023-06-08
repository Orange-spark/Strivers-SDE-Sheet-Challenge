#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* root)
{
    if(root->left==NULL && root->right ==NULL) 
        return true;
    return false;
}

void addLeftnodes(TreeNode<int>* root,vector<int>&ans)
{
    if(!root) return;
    
    TreeNode<int>* temp = root;

    while(!isLeaf(temp))
    {
        ans.push_back(temp->data);

        if(temp->left) temp =temp->left;
        else  temp =temp->right;
    }


}

void inorder(TreeNode<int>* root,vector<int>&ans)
{
    if(!root) return;

    inorder(root->left,ans);
    if(isLeaf(root)) ans.push_back(root->data);
    inorder(root->right,ans);
}

void addrightnodes(TreeNode<int>* root,vector<int>&ans)
{
    if(!root) return;

    vector<int> res;
    TreeNode<int>* temp = root;

    while(!isLeaf(temp))
    {
        res.push_back(temp->data);

        if(temp->right) temp =temp->right;
        else  temp =temp->left;
    }
    for(int i=res.size()-1;i>=0;i--)
    {
        ans.push_back(res[i]);
    }
}


vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(!root) return ans;

    if(isLeaf(root)) return {root->data};

    ans.push_back(root->data);
    addLeftnodes(root->left,ans);
    inorder(root,ans);
    addrightnodes(root->right,ans);

    return ans;
}
