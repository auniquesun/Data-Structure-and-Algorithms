/*
problem：
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

idea:   动态规划的思想，应该能想到；下一步优化的地方就是不开辟 values[] 数组，用常数空间做这题
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        else if(nums.size() == 2)
            return nums[0]<nums[1]?nums[1]:nums[0];
        
        int values[nums.size()];     // 动态规划的思想，定义一个数组，values[i]记录从 nums[0]...nums[i] 抢劫总数最大值，并且不报警
        values[0] = nums[0];    // 初始化
        values[1] = nums[1];

        int prev_max = values[0]; // 记录下面循环中第 i-1 个数之前的最大值，初始化为 nums[0]
        int max_value = values[0]<values[1]?values[1]:values[0];

        for(int i=2; i<nums.size(); i++){
            values[i] = nums[i] + prev_max;

            prev_max = max(prev_max, values[i-1]);  // 下一步新引入了 values[i]，只需取二者最大值
            max_value = max(values[i], max_value);
        }

        return max_value;
    }
};