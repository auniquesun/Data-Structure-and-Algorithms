#include<iostream>
using namespace std;

/*
 *  problem: 判断一颗二叉树是不是对称
 *      对称是什么意思？如果一颗二叉树和它的镜像一样，那么它是对称的
 *      镜像好理解，就是选取一个镜面，把一颗二叉树做镜面对称得到的二叉树
 *
 *  idea:
 *      1. 对二叉树做前序遍历
 *      2. 对二叉树做前序遍历的对称遍历
 *      3. 如果1,2遍历的结果一致，表明该二叉树是对称的
 *      注：遍历的时候考虑了空指针的顺序，如果不考虑空指针出现的位置
 *          对特例的判断可能出错，比如main函数里的二叉树，节点值全部相同
 */

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

bool judge(TreeNode *root1, TreeNode *root2){
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL || root2 == NULL)	//root1，root2 有且仅有一个为空
		return false;
	if(root1->val != root2->val)
		return false;
	return judge(root1->left, root2->right) && judge(root1->right, root2->left);
}

bool isSymmetricTree(TreeNode *root1, TreeNode *root2){
	return judge(root1, root2);
}

int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(7);
	root->left = new TreeNode(7);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(7);;
	root->left->right = new TreeNode(7);
	root->right->left = new TreeNode(7);

	cout << root << " isSymmetricTree? " << isSymmetricTree(root, root) << endl;
	return 0;
}
