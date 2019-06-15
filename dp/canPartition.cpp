/*
problem:
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

idea:
reference:
1. https://i54cxy.com/?p=73
2. https://codereview.stackexchange.com/questions/148157/partition-equal-subset-sum-challenge-leetcode
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int i=0; i<nums.size(); i++)
            sum+=nums[i];
        
        if (sum & 1) return false;
        
        sum >>= 1;
        int dp[sum+1] = {0};
        dp[0] = 1;
        
        for (int i=0; i<nums.size(); i++){
            for (int j=sum; j>=nums[i]; j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};