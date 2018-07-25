#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	problem: 在排序数组中查找元素的第一个和最后一个位置
	给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

	你的算法时间复杂度必须是 O(log n) 级别。

	如果数组中不存在目标值，返回 [-1, -1]。

	示例 1:

	输入: nums = [5,7,7,8,8,10], target = 8
	输出: [3,4]
	示例 2:

	输入: nums = [5,7,7,8,8,10], target = 6
	输出: [-1,-1]

	idea:
	这道题实际很简单，
	扫描数组的同时，用两个位置标记 pos_start，pos_end记录第一个位置和最后一个位置
	中间要判断好 pos_end 的位置移动
*/

class Solution {

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int pos_start = -1, pos_end = -1;	// 初始化为-1，如果数组没有target这个元素，返回-1

        bool flag = true;	// 设置一个标记，当这个标记为 false 时，考虑(nums[i] == target)移动 pos_end
        for (int i = 0; i < nums.size(); ++i)
        {
        	/* code */
        	if(flag == true && nums[i] == target){
        		pos_start = i;	// 标记target起始位置
        		pos_end = i;	// 标记target结束位置
        		flag = false;
        	}
        	else if(flag == false && nums[i] == target){
        		pos_end = i;
        	}

        }

        result.push_back(pos_start);
        result.push_back(pos_end);

        return result;     
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {5,7,7,8,8,10};
	vector nums(arr,arr+6);

	int target;
	cin>>target;

	Solution *solu = new Solution();
    vector<int> result = solu->searchRange(nums, target);
    
	for(int i=0;i<result.size();i++)
    	cout << result[i] << " ";
    cout << endl;

	return 0;
}