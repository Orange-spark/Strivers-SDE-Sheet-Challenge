#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long int max_sum(TreeNode<int> *root,long long int &maxi)
{
    if(!root) return -1;

    long long int left = max_sum(root->left,maxi);

    long long int right =max_sum(root->right,maxi);

    if(left==-1&&right==-1) return root->val;

    if(left==-1) return right+root->val;

    if(right==-1) return left+root->val;

    maxi = max(maxi,root->val+left+right);

    //cout<<"cur Node"<<root->val<<" left "<<left<<" right "<<right<<" maxi "<<maxi<<endl;

    return max(left,right) +root->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return -1;

    long long int maxi=-1;

    max_sum(root,maxi);

    return maxi;
}
