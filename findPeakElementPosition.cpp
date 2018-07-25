#include<iostream>
#include <vector>
// #include <set>	因为数组元素不需要去重，所以没用上
#include <algorithm>

using namespace std;

/*
	problem:寻找峰值
	峰值元素是指其值大于左右相邻值的元素。

	给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

	数组可能包含多个峰值，在这种情况下，※※※返回任何一个峰值所在位置即可。※※※

	你可以假设 nums[-1] = nums[n] = -∞。

	示例 1:

	输入: nums = [1,2,3,1]
	输出: 2
	解释: 3 是峰值元素，你的函数应该返回其索引 2。
	示例 2:

	输入: nums = [1,2,1,3,5,6,4]
	输出: 1 或 5 
	解释: 你的函数可以返回索引 1，其峰值元素为 2；
	     或者返回索引 5， 其峰值元素为 6。
	说明:

	你的解法应该是 O(logN) 时间复杂度的。

	idea:
	根据题意，不存在两个相邻元素相等的情况，nums[-1] = nums[n] = -∞，
	对于一个数组中的一串元素，
	（1）要么递增，
	（2）要么递减，
	（3）要么先增后减，再递归变化
	（4) 要么先减后增，再递归变化
	由此得到：必然存在波峰元素
*/


class Solution {
public:
    int findPeakElementPosition(vector<int>& nums) {	// 我有个疑问，为什么只返回一个峰值位置？因为可能有多个峰值的情况
        for (int i = 0; i < nums.size(); ++i)
        {
        	/* code */
        	if(i==0){	// 边缘情况
        		if(nums.size() >= 2 && nums[i] > nums[i+1])	// 数组中至少有两个元素
        			return i;
        		else if(nums.size() == 1) 	// 数组中只有一个元素，nums[i+1]不存在
        			return i;
        	}
        	else if(i == nums.size() - 1){	// 边缘情况
        		if(nums[i] > nums[i-1])
        			return i;
        	}
        	else{	// 一般情况
        		if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
        			return i;
        	}
        }
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {1,2,1,3,5,6,4};
	vector nums(arr,arr+7);

	Solution *solu = new Solution();
    int pos = solu->findPeakElementPosition(nums);
    
	cout << "Peak Element Position is: " << pos << endl;    

	return 0;
}
