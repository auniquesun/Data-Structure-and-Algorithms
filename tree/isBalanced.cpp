#include<iostream>

using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val){
            this->val = val;
            left = NULL;
            right = NULL;
        }
};

bool isBalanced(TreeNode *root, int *depth){
    if(root == NULL){
        *depth = 0;
        return true;
    }
    int left, right;
    cout << "left: " << left << ", right: " << right << endl;
    if(isBalanced(root->left, &left) && isBalanced(root->right, &right)){
        int diff = left - right;
        if(diff <=1 || diff >=-1){
            *depth = 1+(left<right?right:left);
            return true;
        }
    }
    return false;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    int depth = 0;
    cout << "is this tree balanced? the answer is: " << isBalanced(root, &depth) << endl;
    cout << "tree depth: " << depth << endl;
}
