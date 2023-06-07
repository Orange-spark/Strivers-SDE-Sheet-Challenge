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

int max_dim(TreeNode<int> *root,int &maxi)
{
    if(!root) return 0;

    int left = max_dim(root->left,maxi);
    int right = max_dim(root->right,maxi);

    maxi = max(maxi,left+right+1);

    return max(left,right)+1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    if(!root) return 0;
    int maxi =0;

    max_dim(root,maxi);

    return maxi-1;
}
