#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// ================= problem ================
// 给定一个未排序的数组，请判断这个数组中是否存在长度为3的递增的子序列。
// 要求算法时间复杂度为O(n)，空间复杂度为O(1) 。

// 如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
// 使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。	注意：严格的大于


// 示例:
// 输入 [1, 2, 3, 4, 5],
// 输出 true.

// 输入 [5, 4, 3, 2, 1],
// 输出 false.

// ================= idea ================
// 这个问题可以转化成数组中是否存在这样的 triplet：
// smallest_so_far < second_smallest_so_far < current


bool increasingTriplet(vector<int>& nums) {
	int i;
	int smallest_so_far = INT_MAX;	// 假设它是目前为止向量中最小的值
	int second_smallest_so_far = INT_MAX;	// 假设它是目前为止向量中次小的值

	int n = nums.size();
	int current;

	for(i=0;i<n;i++){
		current = nums[i];
		if(current <= smallest_so_far)	// 这里用到了 if 、else if 、else 语句，只会进入其中一个条件，
										// 而且是先判断 smallest_so_far，保证了其值为最小
										// 加上等号，如果有两个元素相等的情况，不会进入else if
			smallest_so_far = nums[i];
		else if(current <= second_smallest_so_far)	// 后判断 second_smallest_so_far，保证了其值为次小
													// 加上等号，如果有两个元素相等的情况，不会进入else
			second_smallest_so_far = current;
		else
			return true;
	}     

	return false;
}

int main(){
	vector<int> nums = {16,464,4,64,6,464,67};
	cout<<"found increasing triplet: "<<increasingTriplet(nums)<<endl;
}