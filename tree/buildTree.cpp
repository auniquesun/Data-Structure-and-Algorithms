#include<iostream>
#include <vector>
#include <stack>

using namespace std;

// ================== problem =================
// 根据一棵树的前序遍历与中序遍历构造二叉树。

// 注意:
// 你可以假设树中没有重复的元素。

// 例如，给出

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7

// ================== idea ==================
// 已知前序遍历、中序遍历，还原完整的二叉树
// 前序遍历第一个就是数的根节点，然后根据中序遍历，再分出左右子树
// 再往下构造子树的时候仍然是这样的步骤，所以想办法用递归的思想解决问题：
// 	※找出根节点，把一棵树分成根节点，左子树，右子树三部分※
// 	注意找的时候（中序子树，前序子树）下标范围

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {		

		if(preorder.size() != inorder.size())	// 作为一颗树，前序遍历节点数应等于中序遍历节点数
			return NULL;
		if((preorder.size() == 0) || (inorder.size() == 0))	// 有一个为空，表明是一颗空树
			return NULL;

		int root_val = preorder[0];	// preorder 第个一值即为当前子树根节点
		TreeNode* root = new TreeNode(root_val);

		if((inorder.size() > 1) && (preorder.size() > 1)){	// 只有当传入的子树节点数大于1，
															// 即除了根节点至少还有一个节点，
															// 才会递归地构建它的 左子树 和 右子树

			vector<int> iter_left_preorder;	// 下次迭代传入的 左子树preoder
			vector<int> iter_left_inorder;	//下次迭代传入的 左子树inoder
			vector<int> iter_right_preorder;	// 下次迭代传入的 右子树preoder
			vector<int> iter_right_inorder;	//下次迭代传入的 右子树inoder

			int index=0;	// 记录一个下标，这个下标表示inorder中哪个位置的数与root_val相等
			bool flag=false;	// 如果真的存在这样的下标，flag置为true

			int len_inorder = inorder.size();
			for(int i=0;i<inorder.size();i++){
				if((root_val != inorder[i]) && !flag){
					iter_left_inorder.push_back(inorder[i]);
					index++;
				}
				else if(root_val == inorder[i]){
					flag = true;
				}
				else{
					iter_right_inorder.push_back(inorder[i]);
				}
			}
		
			int len_preoder = preorder.size();
			for(int i=1;i<len_preoder;i++){	// for 循环从preorder第二个元素开始，
											// 原因是第一个元素是根节点，在进入for循环前已被处理
				if(i<(index+1)){
					iter_left_preorder.push_back(preorder[i]);
				}
				else
					iter_right_preorder.push_back(preorder[i]);
			}	

			root->left = buildTree(iter_left_preorder, iter_left_inorder);	// 构建左子树
			root->right = buildTree(iter_right_preorder, iter_right_inorder);	// 构建右子树
		}

		return root;
    }
}

int main(int argc, char const *argv[])
{
	/* code */

	int pre[] = {3,9,20,15,7};
	vector<int> preorder(pre,pre+sizeof(pre)/sizeof(pre[0]));
	int in[] = {9,3,15,20,7};
	vector<int> inorder(in,in+sizeof(in)/sizeof(in[0]));

	Solution *solu = new Solution();
	ListNode *head = solu->buildTree(preorder,inorder);
	ListNode *p = head;

	while(p){
		cout << p->val <<endl;
		p = p->next;
	}

	return 0;
}
