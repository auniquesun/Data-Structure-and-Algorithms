#include<iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

/*
    problem: 二叉树的序列化与反序列化
    序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

    请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

    示例: 

    你可以将以下二叉树：

        1
       / \
      2   3
         / \
        4   5

    序列化为 "[1,2,3,null,null,4,5]"

    idea: 
    关键在于序列化的过程，需要用另一个 队列s 记录中间过程中产生的字符串
    反序列化 deserialize 的过程就是：根据序列化的字符串，以层次顺序建立二叉树
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root != NULL){
            string result="";

            // 下面这两个队列很关键，经过反复尝试，用一个队列无法实现“序列化”
            queue<TreeNode*> q; // 存储层次遍历的节点，用于层次遍历
            queue<string> s;    // 存储层次遍历过程中需要记录的字符串，会存储最后几个叶节点产生的 "null" 字符串
                                // 不过不妨事，因为反序列化 deserialize 的过程中会丢弃掉 "null" 串

            s.push("[");
            s.push(to_string(root->val));            
            
            q.push(root);

            while(!q.empty()){    // 层次遍历二叉树的过程中，用另一个队列 s 记录产生的字符串          
                s.push(",");    // 有多少个逗号无所谓，只要起到分隔作用即可，反序列化 deserialize 的过程中会丢弃掉逗号 ','

                TreeNode* cur = q.front();                

                q.pop();

                if(cur->left){
                    s.push(to_string(cur->left->val));  // s 记录中间过程
                    q.push(cur->left);
                }
                else{
                    s.push("null"); // s 记录中间过程
                }

                s.push(",");
                
                if(cur->right){
                    s.push(to_string(cur->right->val)); // s 记录中间过程
                    q.push(cur->right);
                }
                else{
                    s.push("null"); // s 记录中间过程
                }
            }
            s.push("]");

            while(!s.empty()){  // 从对头到队尾组合成完整的 字符串
                result += s.front();
                s.pop();
            }

            return result;
        }else{  // 如果树为空，返回空列表字符串
            return "[]";
        } 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() > 2){
            cout<<"data: "<<data<<endl;
            vector<int> nums;

            string str="";
            for (int i = 0; i < data.length(); ++i) // 还原字符串中的数字
            {
                /* code */
                if((data[i]>='0' && data[i]<='9') || data[i] == '-')    // 数字可能为负，存在负号'-'的情况
                    str += data[i];

                if(data[i] == ',' || data[i] == ']'){
                                                    
                    
                    int num;    // 把字符串转化为整数
                    if(str == "")   // string里可能包含 null 串，此时插入一个特定的数字作为null的标记
                        num = 1111111111;
                    else
                        num = atoi(str.c_str());

                    nums.push_back(num);
                    str = "";
                }
            }

            for (int i = 0; i < nums.size(); ++i)
            {
                /* code */
                cout<<nums[i]<<endl;
            }
            
            TreeNode* root = new TreeNode(nums[0]);
            TreeNode* parent = root;
            
            queue<TreeNode*> q;
            q.push(parent);

            for (int i =0; !q.empty() && i < nums.size(); ++i)  // 根据还原的数字构建二叉树
            {
                /* code */
                if(!q.empty()){
                    parent = q.front();
                    q.pop();                        
                }

                if(2*i+1 < nums.size() && nums[2*i+1] != 1111111111){   // 两个条件都要判断
                    TreeNode* node = new TreeNode(nums[2*i+1]);
                    parent->left = node;
                    q.push(node);
                }

                if(2*i+2 < nums.size() && nums[2*i+2] != 1111111111){
                    TreeNode* node = new TreeNode(nums[2*i+2]);
                    parent->right = node;
                    q.push(node);
                }
            }
    
            string xxx = "-1";  // 测试时使用
            cout << "############## " << atoi(xxx.c_str()) <<endl;

            return root;
        }else{
            return NULL;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
