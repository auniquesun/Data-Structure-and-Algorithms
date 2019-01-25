#include<iostream>
#include<vector>
using namespace std;

/*
problem: 给定一颗二叉树，给定一个数值sum，
		找出二叉树种所有和为sum的路径

		可以看出，路径这个概念很重要，什么是路径呢？
		路径就是从根节点到叶节点的一个节点的集合

idea: 找路径，肯定要遍历树啦，如何遍历？
		不外乎深度优先，广度优先，对应的数据结构分别为栈、队列
		广度优先是做层次遍历用的，不适合本题，（因为层次形不成路径）
		只能用栈啦
		问题本身比较复杂，栈 + 递归 是解决方案
		至于题目里为什么用 vector 当做栈，而不用 STL的 stack呢？
		主要出于这样的考虑： vector 方便知道路径上所有的元素，
							stack 栈顶元素是易知的，其他元素还要不断出栈，
							不如vector方便
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

void findPath(int expectedSum, int currentSum, TreeNode *node, vector<TreeNode*> path){
	if(!node)
		return;

	currentSum += node->val;
	path.push_back(node);
	bool isLeaf = (!node->left && !node->right);

	if(isLeaf && currentSum == expectedSum){
		cout << "find one path: ";
		for(int i=0; i<path.size(); i++)
			cout << path[i]->val << " ";
		cout << endl;
	}

	findPath(expectedSum, currentSum, node->left, path);
	findPath(expectedSum, currentSum, node->right, path);

	path.pop_back();
}

int main(int argc, char const *argv[])
{
	/* code */
	int expectedSum, currentSum = 0;
	cout<<"expectedSum: ";
	cin>>expectedSum;

	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(12);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(7);

	vector<TreeNode*> path;
	findPath(expectedSum, currentSum, root, path);
	return 0;
}
