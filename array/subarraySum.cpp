/*
problem:
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

idea:
我就不明白了，这道题这么做，居然能对
subarray sum，意味着不能修改数组，不能从小到大排列，否则subarray sum就不一样了
所以不能用 small，big 两个指针移动的方法，这是 剑指offer上的一道题，
那个题数组的范围是连续的整数，从小到大排雷
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        if(nums.size() > 0){
            unordered_map<int, int> uo_map;
            int cur_sum = 0;
            for(int i=0; i<nums.size(); i++){
                cur_sum += nums[i];

                if(cur_sum == k)
                    count++;
                if(uo_map.find(cur_sum - k) != uo_map.end())
                    count += uo_map.find(cur_sum - k);

                uo_map[cur_sum]++;
            }
        }
        return count;
    }
};