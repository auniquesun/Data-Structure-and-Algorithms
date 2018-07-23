#include<iostream>
#include <vector>

using namespace std;

/*
	problem：
	给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

	此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

	注意:
	不能使用代码库中的排序函数来解决这道题。

	示例:

	输入: [2,0,2,1,1,0]
	输出: [0,0,1,1,2,2]
	进阶：

	一个直观的解决方案是使用计数排序的两趟扫描算法。
	首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
	你能想出一个仅使用常数空间的一趟扫描算法吗？

	idea：
	（1）既然要求扫描数组一趟，并且使用额外的常数空间，那么肯定不能使用 “对数组排序” 的方法
	（2）一个直观的思想是扫描的过程调换数的位置，使最终的结果0放在数组最左边，2放在最右边，1在中间
	（3）扫描停止的条件是：0,1的位置都已经放好，剩余2的位置自然也就放好了
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() != 0){
        	int left = 0;		// left左边的元素，位置已经放好，全为0
        	int right = nums.size() - 1;	// right右边的元素，位置也已经放好，全为2

        	for (int i = 0; i <= right; )	// 循环条件：
        									// 这里i，right的值都是变化的，需要取到等号，即 i== right 仍然进入循环
        									// 因为此时 swap(i,right) 相当于没交换，但是还可能有 swap(i,left)，这后者交换是可能产生变化的
        	{
        		/* code */
        		if(nums[i] == 0){
        			swap(nums,i,left);
        			left++;
        			i++;	// i 的位置：要始终保持在left的右边 或者 与left相同的位置
        					// 原因是数组是从左往右扫描的，而left左边的元素已经放好，i 无需处理left左边的元素
        		}
        		else if(nums[i] == 1){
        			i++;
        		}
        		else{
        			swap(nums,i,right);
        			right--;	// 这里只做 right-- 操作，没做 i++ 操作，
        						// 原因是 i 与 right位置的数调换后，i位置上的数可能为0，且 i >= left，要对此作处理
        		}
        	}
        }
    }

    void swap(vector<int> &nums, int i, int j){
    	int tmp = nums[i];
    	nums[i] = nums[j];
    	nums[j] = tmp;
    }
};

int main(int argc, char const *argv[])
{
	/* code */

	return 0;
}
