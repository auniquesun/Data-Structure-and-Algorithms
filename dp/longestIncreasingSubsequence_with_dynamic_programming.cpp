#include<iostream>
#include <vector>
#include <climits>

using namespace std;

/*
	problem：Longest Increasing Subsequence
	给定一个无序的整数数组，找到其中最长上升子序列的长度。

	示例:

	输入: [10,9,2,5,3,7,101,18]
	输出: 4 
	解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
	说明:

	可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
	你算法的时间复杂度应该为 O(n2) 。
	进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

	idea：
	（1）递归，求长度为n的最长递增子序列长度，先求 n-1 的，设置边界条件和递增条件，迭代出结果；
		但是随着字符串长度的增长时，递归消耗的空间和时间呈指数级增长，效率低下
	（2）动态规划，开辟大小为 n+1 的数组，存储中间计算结果，后面再次用到时直接从数组读取，
		避免了递归方法中重复计算的开销。
		※ length数组很关键，是动态规划过程中核心的数据结构，注意计算完毕length数组最后一个元素不一定是最优解，需要重新对其排序 ※
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() > 1){
            int n = nums.size();
            int length[n + 1];	// 这个数组存储的内容很关键：length【i】表示长度为i的字符串中最长递增子序列的长度
            
            for(int i=0;i<=n;i++){	// 初始化
            	if(i==0)
            		length[i] = 0;  // 空串的最长递增子序列长度为0        	
                else
                    length[i] = 1;	// 长度为i的串，最长递增子序列长度设为1：在不知道递增递减的情况下，默认每个位置自己递增，长度为1
            }

            for(int i=2;i<=n;i++){
            	for(int j=0;j<i-1;j++){
	            	if(nums[j] < nums[i-1])
	            		length[i] = max(length[i], length[j+1] + 1);    // 动态规划的思想：长度为i的字符串中最长递增子序列的长度 = max(自身长度,前面所有串最大的长度加1)
	            														// 第二个参数，要注意：length[j+1] + 1
	            														// 中length的下标为j+1，而不是j，
	            														// 因为nums[j]对应该数组中第j+1个元素，
	            														// 而length[j+1]表示长度为j+1的串的最长递增子序列的长度                 
                }                
            }

            // sort(length, length+(n+1));	// 返回length数组中最大的元素，未排序之前，length【n】不一定是最大的
            							// 为了提高计算性能，可以不排序，只扫描数组一次找出最大值即可
            int max = INT_MIN;
            for(int i=1;i<=n;i++)
            	if(max<length[i])
            		max = length[i];

            return max;
        }
        else if(nums.size() == 1)
        	return 1;
        else 
            return 0;
    }    
    
    int max(int a, int b){
    	return a>b?a:b;
    }  
};

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {7,5,8,14,23,16,50,20,35};

	int n = sizeof(arr)/sizeof(arr[0]);

	vector<int> nums(arr, arr+n);

	Solution *solu = new Solution();
    int length = solu->lengthOfLIS(nums);

    cout << "max length of nums: " << length << endl;

	return 0;
}