#include<iostream>
#include <queue>
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

void printBTLevelByLevel(TreeNode *root){
	if(!root)
		return;

	queue<TreeNode*> q;
	q.push(root);
	int level = 1;
	int numNextLevel = 0;
	int toBePrinted = 1;

	while(!q.empty()){
		TreeNode *node = q.front();
		q.pop();
		cout << node->val << " ";

		if(node->left){
			q.push(node->left);
			numNextLevel++;
		}
		if(node->right){
			q.push(node->right);
			numNextLevel++;
		}

		toBePrinted--;
		if(toBePrinted == 0){
			cout << "第 " << level << " 层打印完毕" << endl;
			toBePrinted = numNextLevel;
			numNextLevel = 0;
			level++;
		}
	}
}

int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	printBTLevelByLevel(root);
}
