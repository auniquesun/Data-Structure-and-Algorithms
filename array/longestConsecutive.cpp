/*
problem:
    给定一个整型数组，求其中“数值连续子序列”的最大长度，要求时间复杂度为 O（n）
    例如：
    Input: [100, 4, 200, 1, 3, 2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. 
    Therefore its length is 4.

idea：
    首先要注意几个概念，
    1. 数值连续，因为都是整数，就是指两个数字相差1
    2. 子序列，说明这几个数字不一定挨着，数值连续即可

    最容易想到的方法，对这个数组排序，依次扫描，判断前后数字是否连续，找出最大长度；
    但是时间复杂度明显不符合，在这时我想到了另一个原则，“用空间换时间”，因为时间复杂度要求高，
    必然需要特殊的数据结构支持

    这里用到 哈希表，
    a。数组中的每个元素存入哈希表
    b。扫面数组，判断当前数字是否为子序列开头，
        如果是子序列开头，则以此数字为开头，求连续子序列长度
        否则继续扫面数组后续元素
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        if(nums.size() > 0){

        }
        return res;
    }
};