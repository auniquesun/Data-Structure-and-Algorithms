#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*

idea:
这个题出在了动态规划里，但是解法不是动态规划，而且也很简单
定义下面两个变量，
max_so_far跟踪目前为止子数组最大的和，
max_ending_here跟踪当前子数组的和，
max_so_far的值是和max_ending_here比较大小得来的


Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far

上面算法得到的 max_so_far 一定>=0
但是数组元素可能全部为负，所以要判定这种情况，flag及max就是做这个的
*/

class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        else if(nums.size() == 1){
            return nums[0];
        }
        else{
            int max_ending_here = 0;
            int max_so_far = 0;

            bool flag = false;  //假设数组元素全部<0
            int max = nums[0];

            for(int i=0;i<nums.size();i++){
                if(nums[i]>=0)  //如果有>=0的元素，flag置为true
                    flag = true;

                max_ending_here = max_ending_here + nums[i];
                if(max_ending_here < 0)
                    max_ending_here = 0;
                if(max_so_far < max_ending_here)
                    max_so_far = max_ending_here;

                if(max < nums[i])
                    max = nums[i];
            }   //循环结束时，max_so_far的值为非负数，但是有可能数组全为负数，这就要判断flag的值

            if(!flag)
                max_so_far = max;
            return max_so_far;
        }
    }
};

int main(){
    int arr[] = {-2,-1,-3,-4,-1,-2,-1,-5,-4};
    vector<int> nums(arr, arr + 9);

    Solution *solu = new Solution();
    int res = solu->maxSubArray(nums);
    cout << "res: " << res << endl;
}