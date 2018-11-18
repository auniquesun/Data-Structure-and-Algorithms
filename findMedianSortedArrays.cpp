/*
============= problem =============
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

你可以假设 nums1 和 nums2 不同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5

============= idea =============
题目要求时间复杂度为 O(log (m+n))，所以不能结合成一个数组，用快排等方法做
（1）既然时间复杂度有要求，常用的思路就是空间换取时间
 (2) 充分利用两个数组分别有序的特性
    结合以上两点，一个简单有效的方法：
    建立一个空向量，单遍扫描这两个数组，将其有序放置于空向量
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;

        int len1 = nums1.size();
        int len2 = nums2.size();

        int i = 0, j = 0;   //i扫面nums1 j扫面nums2
        while(i<len1 && j<len2){
            if (nums1[i] < nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }else{
                nums.push_back(nums2[j]);
                j++;
            }
        }

        //退出上面的while循环时，一定是 (i<len1 && j<len2) 中有一个不满足或者两个都不满足
        if(i==len1 && j<len2){
            for(;j<len2;j++)
                nums.push_back(nums2[j]);
        }else if(i<len1 && j==len2){
            for(;i<len1;i++)
                nums.push_back(nums1[i]);
        }// 不可能有 i==len1 && j == len2 的情况 必有一个先打破边界

        double median;
        if ((len1+len2)%2 == 0)   // 两个数作平均
            median = (nums[(len1+len2-1)/2] + nums[(len1+len2)/2])/double(2.0);
        else 
            median = double(nums[(len1+len2)/2]);
        return median;
    }
};