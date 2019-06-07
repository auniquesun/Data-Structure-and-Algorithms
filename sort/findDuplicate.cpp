/*
problem:
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

idea:
这个题有个要求，不让修改数组，排序算不算修改呢？
如果不让排序，时间复杂度要求为什么 < O(n2)，应该更少才对呀
思路很简单，因为是取值从1到n，共n+1个数，
    排序，比较前后两个元素是否相同
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                result = nums[i];
                break;
            }
        }
        return result;
    }
};