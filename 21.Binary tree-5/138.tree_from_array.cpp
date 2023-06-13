#include <bits/stdc++.h> 

void in(TreeNode<int>*root);
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
TreeNode<int>* BST(int start,int end,vector<int> &arr)
{
    if(start<=end)
    {
        int mid = (start+end)/2;

        // cout<<"S "<<start<<" e "<<end<<endl;
        // cout<<"m "<< mid<<endl;

        TreeNode<int> *root = new TreeNode<int>(arr[mid]);

        root->left = BST(start,mid-1,arr);
        root->right = BST(mid+1,end,arr);

        // cout<<"trav : "<<endl;
        // in(root);
        // cout<<endl;

        return root;
    }
    return NULL;
}

void in(TreeNode<int>*root)
{
    if(!root) return;

    in(root->left);
    cout<<root->val<<" ";
    in(root->right);
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
   TreeNode<int> * root = BST(0,n-1,arr);
   //in(root);
   //cout<<endl;
}
