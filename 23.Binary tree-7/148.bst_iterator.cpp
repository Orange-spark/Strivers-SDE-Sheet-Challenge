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

class BSTiterator
{
    stack<TreeNode<int>*> st;

    void rev_inorder(TreeNode<int> *root)
    {
        if(!root) return;

        rev_inorder(root->right);
        st.push(root);
        rev_inorder(root->left);
    }

    public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        rev_inorder(root);
    }

    int next()
    {
        // write your code here
        int x = st.top()->data;
        st.pop();

        return x;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
