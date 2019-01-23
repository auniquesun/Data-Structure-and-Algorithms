#include<iostream>
#include <cmath>
#include <vector>

using namespace std;

// ====================== problem ======================
// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

// 说明：解集不能包含重复的子集。

// 示例:

// 输入: nums = [1,2,3]
// 输出:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
// ================= idea =================
// 对于一个有n个元素的集合，它的子集共有pow（2，n）个
// x1,x2,...,xn	每个元素有两种可能：在某个子集，为1；不在某个子集，为0
// 用长度为n的0,1二进制串模拟这些组合：0表示对应的元素不在子集，1表示在这个子集

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > result;

        if(nums.size() != 0){
	        vector<int> subset;
	        int num_subsets = pow(2,nums.size());

	        for(int i=0;i<num_subsets;i++){
	        	for(int j=0;j<nums.size();j++)
	        		if(i & (1<<j))				// x<<y，表示把x转换成二进制数后的每个bit向左移动y步
	        									// a & b，表示把a，b转为二进制数，按位取余
	        			subset.push_back(nums[j]);
	        	result.push_back(subset);	// 内层循环结束，找到一个subset
	        	subset.clear();		// 为下次循环清空本次subset
	        }
        }

        return result;
    }    
};

int main(){
	vector<int> nums;
	int item;
	while(cin>>item && item != -1){
		nums.push_back(item);
	}

	Solution *solu = new Solution();
	vector< vector<int> > result = solu->subsets(nums);
	
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++)
			cout << result[i][j] << " ";
		cout << endl;
	}

	return 0;
}
