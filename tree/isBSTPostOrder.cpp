#include<iostream>
#include <vector>
using namespace std;

/*
 * problem: 给定一个数字序列，判定这个数字序列是否为某颗二叉排序树的后续遍历
 *
 * idea: 后续遍历最后一个元素为根节点，按照BST性质，划分左右子树，递归判断
 * */

// 务必注意 BST二叉搜索树的性质，左节点值小于根，右节点值大于根
bool isBSTPostOrder(vector<int> sequence){
	int len = sequence.size();
	if(len == 0)	//空树认为非 BST post order
		return false;
    if(len == 1)    //sequence中只剩一个节点的时候，必须有返回值,
                    //否则会陷入死循环，并且返回值要为true
        return true;

	// sequence的最后一个元素为树根
	int root = sequence[len-1];
	vector<int> left;
	vector<int> right;
	// 从前到后找到第一个比树根大的元素
	int i,j;
	for (i = 0; i < len; ++i)
	{
		/* code */
		if(sequence[i]>root)
			break;
		left.push_back(sequence[i]);
	}

	for (j = i; j < len-1; ++j)
	{
		/* code */
		if(sequence[j]<root)	//右子树不能小于根节点
			return false;
		right.push_back(sequence[j]);
	}

	// 经过上面两个循环，认为leftBST 为true, rightBST同理
	bool leftBST = true;
	if(left.size()>0)
		leftBST = isBSTPostOrder(left);
	bool rightBST = true;
	if(right.size()>0)
		rightBST = isBSTPostOrder(right);

	return (leftBST && rightBST);
}

int main(int argc, char const *argv[])
{
	/* code */
	//int arr[] = {5,7,6,9,11,10,8};
	int arr[] = {7,4,6,5};
	vector<int> sequence(arr, arr + sizeof(arr)/sizeof(arr[0]));
	cout << "isBSTPostOrder? " << isBSTPostOrder(sequence) << endl;
	return 0;
}
