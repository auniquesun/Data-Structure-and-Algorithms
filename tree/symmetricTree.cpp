#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v){
		val = v;
		left = NULL;
		right = NULL;
	}
};

void *symmetricTree(TreeNode *root){
	if(!root)
		return NULL;

	TreeNode *tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	if(root->left)
		return symmetricTree(root->left);
	if(root->right)
		return symmetricTree(root->right);
}

void inOrder(TreeNode *root){
	if(!root)
		return;
	inOrder(root->left);
	cout << root->val << endl;
	inOrder(root->right);
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(5);

    cout << "origin:" << endl;
	inOrder(root);

	symmetricTree(root);

    cout << "symmetric:" << endl;
	inOrder(root);
	return 0;
}
