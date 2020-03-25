#include "public.h"

void  preOrderWithRecursion(TreeNode *root){
    if (root == NULL)
        return;

    preOrderWithRecursion(root->left);
    cout << root->val << endl;
    preOrderWithRecursion(root->right);
    
}


int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    preOrderWithRecursion(root);
}
