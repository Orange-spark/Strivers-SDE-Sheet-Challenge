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

void inorder(TreeNode<int> *root, int &k,int &num)
{
    if(!root) return;

    inorder(root->left,k,num);
    k--;
    if(k==0) num = root->data;
    inorder(root->right,k,num);

}

int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int num =-1;

    inorder(root,k,num);

    return num;
}
