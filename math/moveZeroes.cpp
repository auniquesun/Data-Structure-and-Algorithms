/*
problem:
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

idea:
MSRA 面试原题，一位很友好的小姐姐，当时居然在她百般提醒下才写出来最高效的解法
这道题在 leetcode 属于 easy型的，惭愧啊
*/

class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    // solution one
    void moveZeroes(vector<int>& nums) {
        if(nums.size() > 1){
            int k=1;
            for(int i=0; i<nums.size()-1; ){
                if(nums[i] == 0){   // 发现了一个0
                    bool flag = false;  // 默认nums[i] 之后全是0
                    for(int j=k; j<nums.size();){ // 判断nums[i] 之后是否有非0值，有则交换
                        if(nums[j] != 0){
                            swap(nums, i, j);   // 交换完之后，nums[i] 变为非0，nums[j]变为0，nums[i],nums[j]之间的数全为0
                            i++;    // i重新定位到第一个0
                            k = j+1;
                            flag = true;
                            break;
                        }
                        else j++;
                    }
                    if(!flag)   // 表明nums[i]之后没找到非0值，全是0
                        break;  
                }
                else i++;
            }
        }
    }
    // solution two    
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0)
                nums[count++] = nums[i];
        }
        while(count<nums.size())
            nums[count++] = 0;
    }
};