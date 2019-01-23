
/*
problem:
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

idea:
思想很简单，用map记录每个关键字出现的次数
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> key2count; //记录 数字 --> 次数；这道题关键要知道map怎么用

        for(int i=0;i<nums.size();i++){
            key2count[nums[i]] = 0;
        }

        for(int i=0;i<nums.size();i++){
            key2count[nums[i]]++;
        }

        for(int i=0;i<nums.size();i++){
            if(key2count[nums[i]] == 1)
                return nums[i];
        }
    }
};