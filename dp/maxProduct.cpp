/*
problem:
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

idea:
这个题吧，因为数组中有正数、负数、0是不确定的，而且要求连乘的最大值，
        负负得正，正正得正，所以情况很多
    整个计算机科学里，初始化都非常重要，这里设置两个数组
    max_ending_here[i], 记录以nums【i】结尾的子数组最大正数
    min_ending_here[i], 记录以nums【i】结尾的子数组最小负数

    如果当前数值nums[i+1]为正，则与 max_ending_here[i] 相乘, 求最大
    如果当前数值nums[i+1]为负，则与 min_ending_here[i] 相乘，求最大
    求最小同理
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()>0){
            // 记录乘积最大的正数，初始化为 nums[0]，nums[0]不是正数也没关系，后续通过max可调整
            int max_ending_here [nums.size()];
            max_ending_here[0] = nums[0];
            // 记录乘积最小的负数，初始化为 nums[0]，nums[0]不是负数也没关系，后续通过min可调整
            int min_ending_here [nums.size()];
            min_ending_here[0] = nums[0];
            int max_so_far = nums[0]; // 记录最终的 max_product

            for(int i=1; i<nums.size(); i++){
                if(nums[i] > 0){
                    max_ending_here[i] = max(nums[i], max_ending_here[i-1] * nums[i]);
                    min_ending_here[i] = min(nums[i], min_ending_here[i-1] * nums[i]);
                }
                else{
                    max_ending_here[i] = max(nums[i], min_ending_here[i-1] * nums[i]);
                    min_ending_here[i] = min(nums[i], max_ending_here[i-1] * nums[i]);
                }

                if(max_so_far < max_ending_here[i])
                    max_so_far = max_ending_here[i];
            }

            return max_so_far;
        }
        else{
            cout << "error: nums must non-empty";
            return 0;
        }
    }
};