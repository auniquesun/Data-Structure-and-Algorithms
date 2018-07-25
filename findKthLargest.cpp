#include<iostream>
#include <vector>
// #include <set>	因为数组元素不需要去重，所以没用上
#include <algorithm>

using namespace std;

/*
	problem:
	在未排序的数组中找到第 k 个最大的元素。
	※※※ 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 ※※※

	示例 1:

	输入: [3,2,1,5,6,4] 和 k = 2
	输出: 5
	示例 2:

	输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
	输出: 4
	说明:

	你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

	idea:
	思想很简单：对原数组排序，但是要注意数组中可能有重复元素，
			   但是根据题意，不需要元素去重，只需要找到数组排序后的"第 k 个最大的元素"
*/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {                

        sort(nums.begin(), nums.end());	// 默认从小到大排列，即升序排列

        for(int i=0;i<nums.size();i++)
        	cout << nums[i] << " ";
        cout << endl;

        return nums[(nums.size() - 1) - (k - 1)];	// 返回数组排序后 Kth largest item
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {3,2,3,1,2,4,5,5,6};
	vector nums(arr,arr+9);

	Solution *solu = new Solution();
    int Kth = solu->findKthLargest(nums,4);
    
	cout << result[i] << "Kth largest item: " << Kth << endl;    

	return 0;
}