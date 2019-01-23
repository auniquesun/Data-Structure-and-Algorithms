#include<iostream>
#include<vector>

using namespace std;

/*
problem：
给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

idea:
1. 时间复杂度限定在O(n),这就决定了不能用二重循环做
2. 因为vector中的元素是整型的，也不用考虑乘积溢出的问题，如果溢出题目就不对了
3. 尝试过对nums中每个元素取log，再相加的方法；但是log的定义域>0, 额外考虑正负号很麻烦，不适合本题

决定用空间换时间的方法做：
1. 开辟两个大小均为n的数组，left，right
2. left[i]存储 i 左边所有数的乘积；right[i]存储 i 右边所有数的乘积
3. 第i位置上的结果：left[i] × right[i]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        // nums为空或者只有1个元素，res都应该为空
        if(nums.size() == 0 || nums.size() == 1)
            return res;        

        int *left = new int [nums.size()];
        int *right = new int[nums.size()];

        left[0] = 1, right[nums.size()-1] = 1;  //赋初值很重要

        for(int i=1;i<=nums.size()-1;i++){
            left[i] = nums[i-1] * left[i-1];  //left[i-1]表示nums[i-1]"左侧"所有数的 乘积
        }

        for(int j=nums.size()-2;j>=0;j--){  //right[i-1]表示nums[i-1]"右侧"所有数的 乘积
            right[j] = nums[j+1] * right[j+1];
        }

        for(int i=0;i<nums.size();i++){
            int product = left[i] * right[i];
            res.push_back(product);
        }

        return res;
    }
};

int main()
{
    int a,b,c,d;
    cin>>a>>b;
    int arr[] = {a,b};
    vector<int> nums(arr,arr+2);
    Solution *solu = new Solution();
    vector<int> res = solu->productExceptSelf(nums);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
}    
