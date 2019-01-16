/*
problem: 存在重复元素
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true

idea:
很好想到，集合中的元素不会重复，所以：
1. 定义一个集合s
2. 扫描数组，如果元素不存在于s，则把该元素插入s；如果存在，表明数组中有重复元素，return true
3. 循环结束，返回false
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;        
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]) == s.end())  //s中不存在nums[i]
                s.insert(nums[i]);
            else return true;
        }

        return false;
    }
};