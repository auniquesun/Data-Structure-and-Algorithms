#include<iostream>
#include <vector>
#include <stack>

using namespace std;

// ================== problem =================
// 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回锯齿形层次遍历如下：

// [
//   [3],
//   [20,9],
//   [15,7]
// ]
// ================== idea ==================
// 此题不同于层次遍历，而是蛇形遍历，即：
	// 先从左往右，再从右往左，循环下去
	// 依据这种情况，数据结构肯定要用到"栈"
// 基本的思想是：
// 	（1）先不管根节点（最后处理）
// 	（2）从第二层节点开始，从左到右遍历节点，依次放入一个栈	left2right
// 		 当left2right节点出栈时，把节点依次存入向量 level （经过入栈出栈操作，第二层节点 从右到左 逆序排列）
// 		 节点存入向量level的同时，把它的 right和left children 放入另一个栈 right2left
// 	（3）当right2left节点出栈时，把节点依次存入向量 level （经过入栈出栈操作，第三层节点 从左到右 逆序排列）
// 		 节点存入向量level的同时，把它的 left和right children 放入另一个栈 left2right
// 	（4）重复（2）（3），直到 left2right 和 right2left 均为空
//  （5）把根节点放入二维向量起始处

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > result;	// 存放返回结果
        if(root != NULL){

	        vector<int> level;	// 存放每层的元素	     
	        
	        TreeNode *cur = root;	        

	        stack<TreeNode*> left2right;	// 存放偶数层节点（如果存在偶数层）
	        								// 把该层树节点从左到右入栈，出栈时就是从右到左的顺序，按照出栈顺序插入level

	        stack<TreeNode*> right2left;	// 存放奇数层节点（如果存在奇数层）
	        								// 把该层树节点从右到左入栈，出栈时就是从左到右的顺序，按照出栈顺序插入level
			
	        // 进入while循环前，进行必要的初始化
			if(cur->left)
				left2right.push(cur->left);
			if(cur->right)
				left2right.push(cur->right);

	        bool flag = true;
			bool sign = true;

	        while(flag){	        	


	        	if(sign){
		        	
	        		while(!left2right.empty()){
	        			TreeNode *p = left2right.top();
	        			level.push_back(p->val);

	        			if(p->right)
	        				right2left.push(p->right);
	        			if(p->left)
	        				right2left.push(p->left);

	        			left2right.pop();
	        		}
	        		if(level.size() > 0){
	        			result.push_back(level);
		        		level.clear();
	        		}

	        		if(!right2left.empty()){	// right2left 非空，说明下一层有节点
	        			sign=false;
	        			cur = right2left.top();
	        		}
	        		else
	        			flag = false;

	        	}
			if(!sign){

	        		while(!right2left.empty()){
	        			TreeNode *p = right2left.top();
	        			level.push_back(p->val);

	        			if(p->left)
	        				left2right.push(p->left);
	        			if(p->right)
	        				left2right.push(p->right);

	        			right2left.pop();
	        		}
	        		if(level.size() > 0){
	        			result.push_back(level);
		        		level.clear();
	        		}
		        		
	        		if(!left2right.empty()){	// left2right 非空，说明下一层有节点
	        			sign=true;
	        			cur = left2right.top();
	        		}
	        		else
	        			flag = false;

	        	}
	        }

	        // 把根节点插入最前面
        	level.push_back(root->val);
    		result.insert(result.begin(), level);	
    		level.clear();
    
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(4);
	root->left->left->left->left = new TreeNode(5);

	Solution *solu = new Solution();
	vector< vector<int> > result = solu->zigzagLevelOrder(root);
	for(int i=0;i < result.size();i++){
		for(int j=0;j < result[i].size();j++)
			cout << result[i][j] << " ";
		cout<<endl;
	}

	return 0;
}
