void help(BinaryTreeNode<int>*root,BinaryTreeNode<int>*&prev,BinaryTreeNode<int>*&head){
    if(root==NULL)return;
    help(root->left,prev,head);
    if(head==NULL)head=root;
    root->left=prev;
    if(prev!=NULL)prev->right=root;
    prev=root;
    help(root->right,prev,head);   
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* p=NULL;
    BinaryTreeNode<int>* head=NULL;
    help(root,p,head);
    return head;
}
