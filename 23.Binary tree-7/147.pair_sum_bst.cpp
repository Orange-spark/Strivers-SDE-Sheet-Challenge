#include <bits/stdc++.h> 
using namespace std;
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
class BSTiterator
{
    stack<BinaryTreeNode<int>*> st;

    void rev_inorder(BinaryTreeNode<int> *root,bool left)
    {
        if(!root) return;

        if(left)
        {
            rev_inorder(root->right,left);
            st.push(root);
            rev_inorder(root->left,left);
        }
        else{
            rev_inorder(root->left,left);
            st.push(root);
            rev_inorder(root->right,left);
        }
    }

    public:
    BSTiterator(BinaryTreeNode<int> *root,bool left)
    {
        // write your code here
        rev_inorder(root,left);
    }

    int next()
    {
        // write your code here
        return st.top()->data;;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }

    void rem()
    {
        if(!st.empty())
        {
            st.pop();
        }
    }
};



bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    BSTiterator it1(root,true);
    BSTiterator it2(root,false);

    while(it1.hasNext()&&it2.hasNext())
    {
        int sum = it1.next()+it2.next();
        if(sum==k) return true;

        if(sum<k)
        {
            it1.rem();
        }
        else    
            it2.rem();

    }

    return false;
}
