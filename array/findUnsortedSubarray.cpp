/*
problem:
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

idea:   reference —— https://leetcode.com/articles/shortest-unsorted-continous-subarray/
the idea behind this method is that the correct position of the minimum
 element in the unsorted subarray helps to determine the required left 
 boundary. Similarly, the correct position of the maximum element in 
 the unsorted subarray helps to determine the required right boundary.

Thus, firstly we need to determine when the correctly sorted array 
goes wrong. We keep a track of this by observing rising slope starting 
from the beginning of the array. Whenever the slope falls, we know that 
the unsorted array has surely started. Thus, now we determine the minimum 
element found till the end of the array numsnums, given by minmin.

Similarly, we scan the array numsnums in the reverse order and when 
the slope becomes rising instead of falling, we start looking for 
the maximum element till we reach the beginning of the array, given by maxmax.

Then, we traverse over numsnums and determine the correct position of 
minmin and maxmax by comparing these elements with the other array 
elements. e.g. To determine the correct position of minmin, we know 
the initial portion of numsnums is already sorted. Thus, we need to 
find the first element which is just larger than minmin. Similarly, 
for maxmax's position, we need to find the first element which is 
just smaller than maxmax searching in numsnums backwards.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;

        int max_value = INT_MIN;
        int min_value = INT_MAX;
        bool flag = false;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] < nums[i-1])
                flag = true;
            if(flag)
                min_value = min(min_value, nums[i]);
        }

        flag = false;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] > nums[i+1])
                flag = true;
            if(flag)
                max_value = max(max_value, nums[i]);
        }

        int start = 0;  // 赋个初值很重要
        int end = -1;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] > min_value){    // 找到第一个比 min_value 大的值的位置，从前到后找
                start = i;
                break;
            }
        for(int i=nums.size()-1; i>=0; i--)
            if(nums[i] < max_value){    // 找到第一个比 max_value 小的值的位置，从后到前找
                end = i;
                break;
            }
        return (end-start < 0 ? 0 : end - start + 1);  // end-start < 0 表示没有数组逆序
    }
};