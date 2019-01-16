/*
problem: 最接近的三数之和
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

idea:
1. 暴力搜索是一种方法，时间复杂度为O(n^3)，不好
2. 可以先对原数组排序，a.固定住一个位置，b.再与剩余两个位置的数加和
	根据与target的大小关系动态调整，这样时间复杂度为O(n^2)
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
		int closest = INT_MAX/2;    //closest初值不能赋值为INT_MAX, 很容易溢出
									//取INT_MAX/2就比较恰当

		for(int i=0;i<nums.size();i++)        
		{
			int j = i+1;
			int k = nums.size()-1;

			while(j<k){
				int num = nums[i]+nums[j]+nums[k];

				if((num-target)==0){
					closest = num;
					return closest;
				}
				else if((num-target)<0){
					if(abs(num-target) < abs(closest-target))
						closest = num;
					j++;
				}
				else{
					if(abs(num-target) < abs(closest-target))
						closest = num;
					k--;
				}
			}
		}
		return closest;
    }
};