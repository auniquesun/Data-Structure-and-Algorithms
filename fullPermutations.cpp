#include<iostream>
#include <vector>

using namespace std;


// ===================== problem ====================
// 全排列
// 给定一个没有重复数字的序列，返回其所有可能的全排列。

// 示例:

// 输入: [1,2,3]
// 输出:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]


// ====================== idea ======================
// backtrack 回溯的思想


class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {	// 求给定数字序列的所有排列
        vector< vector<int> > result;	// 存放返回结果
        if(nums.size() != 0){
        	int *s = new int[nums.size()];	// 用来存放每一种组合情况
        	for(int i=0;i<nums.size();i++)	// 为s数组初始化
        		s[i] = nums[i];
        	int left = 0;	//	初始情况下，数组左边界，递归的过程中会变化
        	int right = nums.size() - 1;	// 数组右边界
        	find(s,left,right,result);	
        }
        return result;
    }
    void find(int *s, int left, int right, vector< vector<int> > &result){	// result 为应用传递
    	if(left == right){
    		vector<int> permution;
    		for(int i=0;i<=right;i++)
    			permution.push_back(s[i]);
    		result.push_back(permution);
    		permution.clear();
    	}
    	else{
    		for(int i=left;i<=right;i++){
    			swap(s+left,s+i);	// 交换两数的位置
    			find(s,left+1,right,result);	// 递归
    			swap(s+left,s+i);	// 回溯：再次交换两数的位置，相当于进入循环后，两数的位置没有交换
    		}
    	}
    }
    void swap(int *a,int *b){	// 传来的是指针
    	int tmp = *a;	// 交换的是指针指向存储空间对应的值
    	*a = *b;
    	*b = tmp;
    }
};

int main(){
	vector<int> nums;
	int item;
	while(cin>>item){
		nums.push_back(item);
	}

	Solution *solu = new Solution();
	vector< vector<int> > result = solu->permute(nums);
	
	for(int i=0;i<result.size();i++)
		cout << result[i] << " ";
	cout << endl;

	return 0;
}
