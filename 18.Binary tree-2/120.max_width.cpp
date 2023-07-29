#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    int ms=1;
    while(!q.empty()){
        int s=q.size();
        ms=max(ms,s);
        while(s--){
            auto fr=q.front();
            q.pop();
            if(fr->left){
                q.push(fr->left);
            }
            if(fr->right){
                q.push(fr->right);
            }
        }
    }
    return ms;
}
