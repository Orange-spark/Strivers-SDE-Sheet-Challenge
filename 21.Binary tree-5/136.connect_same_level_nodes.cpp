#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        int size =q.size();

        for(int i=0;i<size;i++)
        {
            auto p = q.front();
            q.pop();

            if(i!=size-1)
                p->next =q.front();

            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
    }

}
