#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/
bool trace_path(TreeNode<int>* root,int x,vector<int> &ans)
{
	if(!root) return false;

	if(root->data == x){
		ans.push_back(x);
		return true;
	} 

	ans.push_back(root->data);
	bool left = trace_path(root->left,x,ans);
	bool right = trace_path(root->right,x,ans);

	if(left or right)
		return true;
	
	ans.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	if(!root) return ans;

	trace_path(root,x,ans);

	return ans;
}
