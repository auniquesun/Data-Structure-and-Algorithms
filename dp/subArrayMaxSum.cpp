#include<iostream>
#include <vector>
using namespace std;

/*
problem: 给定一个数组，有正数、负数、零，
		求此数组所有子数组的最大和，要求时间复杂度为O(n)

idea: 动态规划的思想，新建一个数组与原数组长度相同的数组sum，
		sum[i]表示以nums[i]结尾的子数组的最大和，具体地：
		a. 初始化 cur_sum = 0
		b. for num in nums 
			if cur_sum + num >= num
				cur_sum += num
			else
				cur_sum = num
			sum[i] = cur_sum
		c. 求出 sum 后，扫描一遍，求出最大值即可

		更简单的做法，不开辟sum数组，只维护 cur_sum、max_sum两个变量
		直接返回max_sum
*/

int subArrayMaxSum(vector<int> nums){
	if(nums.size() > 0){
		int max_sum = nums[0];
		int cur_sum = 0;

		for(int i=0; i<nums.size(); i++){
			if(cur_sum + nums[i] >= nums[i])
				cur_sum += nums[i];
			else
				cur_sum = nums[i];

			if(cur_sum > max_sum)
				max_sum = cur_sum;
		}
		return max_sum;
	}
	else{
		cout << "nums 为空数组, 返回0值" << endl;
		return 0;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int n, val;
	cout << "n: ";
	cin >> n;

	vector<int> nums;
	for(int i=0; i<n; i++){
		cin >> val;
		nums.push_back(val);
	}

    cout << "subArrayMaxSum: " << subArrayMaxSum(nums) << endl;

	return 0;
}
