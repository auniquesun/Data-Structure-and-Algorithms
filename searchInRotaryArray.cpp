#include<iostream>
#include <vector>

using namespace std;

/*
	problem: 搜索旋转排序数组
	假设按照"升序排序"的数组在预先未知的某个点上进行了"旋转"。

	( 例如，数组 [0,1,2,4,5,6,7] "可能变为" [4,5,6,7,0,1,2] )。

	搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

	你可以假设数组中不存在重复的元素。

	你的算法时间复杂度必须是 O(log n) 级别。

	示例 1:

	输入: nums = [4,5,6,7,0,1,2], target = 0
	输出: 4
	示例 2:

	输入: nums = [4,5,6,7,0,1,2], target = 3
	输出: -1

	idea:
	因为数组是升序排列的，而且可能在某个点处作了旋转
	（1）如果第一个元素小于target，（数组没做旋转时，可能存在target；数组做了旋转，也可能存在target），从头往后搜索
	（2）如果第一个元素等于target，返回头元素位置
	（3）如果第一个元素大于target，数组做了旋转，才可能存在target，从末尾往回搜索
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() > 0){	// 如果数组不为空
        	if(nums[0] > target){     // 如果第一个元素大于target
        		for (int i = nums.size() - 1; i > 0; --i)
        		{
        			/* code */
        			if(nums[i] == target)
        				return i;
        		}
        		return -1;
        	}else if(nums[0] == target){	// 如果第一个元素等于target
        		return 0;
        	}else{	// 如果第一个元素小于target
        		for (int i = 0; i < nums.size(); ++i)
        		{
        			/* code */
        			if(nums[i] == target)
        				return i;
        		}
        		return -1;
        	}
        }
        else{	// 如果数组为空
        	return -1;
        }
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {4,5,6,7,0,1,2};
	vector nums(arr,arr+7);

	int target;
	cin>>target;

	Solution *solu = new Solution();
    int pos = solu->search(nums, target);
    	
    cout << "position of target: " << pos << endl;

	return 0;
}