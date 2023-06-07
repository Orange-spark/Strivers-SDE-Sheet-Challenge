#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> post;

    TreeNode* temp = root;
    stack<TreeNode*> st;

    while(!st.empty() or temp)
    {
        if(temp)
        {
            st.push(temp);
            temp=temp->left;
        }
        else{
            
            if(st.top()->right) 
            {
                temp =st.top()->right;
            }
            else{
                auto node = st.top();
                st.pop();

                post.push_back(node->data);

                while(!st.empty()&&node == st.top()->right)
                {
                    node = st.top();
                    st.pop();

                    post.push_back(node->data);
                }
                temp = NULL;
            }

        }
    }
    return post;
}
