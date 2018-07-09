#include<iostream>
#include <vector>

using namespace std;

// =================== problem ==================
// 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

// 说明：
// ※你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。※

// 示例 1:

// 输入: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// 输出: 1
// 示例 2:

// 输入: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// 输出: 3

// ================== idea ==================
// 有这样的基本规律：对于二叉搜索树，它的中序遍历结果是节点值从小到大的排列
// 要寻找 这棵树 中第k小的值，只需要返回中序遍历后的第 k-1 个元素

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {	// 题目已经假设k是有效的，1<=k<=节点总数
		vector<int> nums;	
		inOrder(root, nums);

		return nums[k-1];	// 因为下标是从0开始的，所以 nums[k-1] 即为第k个最小值        
    }
    void inOrder(TreeNode *root, vector<int> &nums){	// 中序遍历 二叉搜索树，得到的结果是从小到大依次排列的数组
    													// nums 是引用传递，从始至终只有一个nums，只在这个nums里添加元素
    	if(root == NULL)
    		return;

    	inOrder(root->left, nums);
    	nums.push_back(root->val);
    	inOrder(root->right, nums);
    }
};

int main(){
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution *solu = new Solution();
	int kth = solu->kthSmallest(root, 2);
	
	cout << kth << endl;

	return 0;
}