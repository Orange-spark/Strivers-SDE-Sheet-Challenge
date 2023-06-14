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

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    queue<TreeNode<int>*> q;
    q.push(root);

    string s="";

    while(!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            auto p = q.front();
            q.pop();

            if(p)
            {
                s+=to_string(p->data)+" ";

                q.push(p->left);
                q.push(p->right);
            }
            else
            { 
               s+="-1 ";
            }
        }
    }
    //cout<<s<<endl;
    return s;
}

TreeNode<int>* deserializeTree(string &s)
{
 //    Write your code here for deserializing the tree
    if(s.empty() or s[0]=='-') return NULL;

    queue<TreeNode<int>*> q;

    stringstream ss(s);
    string item;

    getline(ss,item,' ');

    TreeNode<int> * root = new TreeNode<int>(stoi(item));

    q.push(root);

    while(!q.empty())
    {
        auto p = q.front();
        q.pop();

        getline(ss,item,' ');
        if(item=="-1")
        {
            p->left = NULL;
        }
        else{
            p->left = new TreeNode<int>(stoi(item));
            q.push(p->left);
        }

        getline(ss,item,' ');
        if(item=="-1")
        {
            p->right = NULL;
           
        }
        else{
            p->right = new TreeNode<int>(stoi(item));
            q.push(p->right);
        }
    }

    return root;
}


