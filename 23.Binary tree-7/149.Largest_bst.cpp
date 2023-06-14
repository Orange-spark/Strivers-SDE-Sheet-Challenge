#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
struct Node{
    int maxi,mini,cnt;

    Node(int x,int y,int z)
    {
        cnt = z;
        mini = x;
        maxi = y;
    }

};

Node check(TreeNode<int>* root)
{
    if(!root) return Node(INT_MAX,INT_MIN,0);

    Node left = check(root->left);
    Node right = check(root->right);
    
    int x = root->data;
    if(x>left.maxi && x<right.mini)
    {
        return Node(min(left.mini,min(x,right.mini)),max(left.maxi,max(x,right.maxi))
        ,1+left.cnt+right.cnt);
    }
    
    return Node(INT_MIN,INT_MAX,max(left.cnt,right.cnt));
}


int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    
    Node n = check(root);
    return n.cnt;
}
