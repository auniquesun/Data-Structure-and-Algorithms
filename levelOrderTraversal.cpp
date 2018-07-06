#include<iostream>
#include <vector>
#include <queue>

using namespace std;

// ================== idea ==================
// 层次遍历，肯定要用到队列

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
	        queue<TreeNode*> node_pointer_queue;	        

	        int layer = 1;	// 存放层次遍历到了哪一层，因为根节点非空，所以初值设为1
	        int layer_back;	// 存放 layer 的备份，如果 layer 向下走了一层，通过比较 layer_back 和 layer 的值就能知道

	        bool flag = true;
	        while(flag){
	        	layer_back = layer;

	        	level.push_back(cur->val);
	        	if(cur->left)
	        		node_pointer_queue.push(cur->left);
	        	if(cur->right)
	        		node_pointer_queue.push(cur->right);

	        	if(cur->left || cur->right)	// 只要左子树或者右子树非空，层数就加1
	        		layer++;	

	        	if((layer_back != layer)){	// 第一个条件很好理解，cur要跨到下一层的时候，level要放入result并清空
	        		// 第二个条件表明这棵树只有根节点，原因是while循环至少要执行一次，layer==1说明上面cur->left和cur->right都为空
	        		result.push_back(level);
	        		level.clear();
	        	}

	        	if(node_pointer_queue.empty() == true)	// 层次遍历退出的条件很简单，就是队列为空
	        		flag = false;	 
	        	else{
		        	cur = node_pointer_queue.front();
		        	node_pointer_queue.pop();	        		
	        	}      	
	        }

	        result.push_back(level);	// 最后一层因为不满足 (layer_back != layer) ，
	        							// 所以while循环里并没有加入这一次，要在外面加入
	        level.clear();
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution *solu = new Solution();
	vector< vector<int> > result = solu->zigzagLevelOrder(root);
	for(int i=0;i < result.size();i++){
		for(int j=0;j < result[i].size();j++)
			cout << result[i][j] << " ";
		cout<<endl;
	}

	return 0;
}