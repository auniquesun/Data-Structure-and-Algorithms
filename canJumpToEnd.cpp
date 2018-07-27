#include<iostream>
#include <vector>
#include <climits>

using namespace std;

/*
	problem: 跳跃游戏
	给定一个非负整数数组，你最初位于数组的第一个位置。

	数组中的每个元素代表你在该位置可以跳跃的"最大长度"。	// 意味着每次跳跃的长度可以小于最大长度

	判断你是否能够到达最后一个位置。

	示例 1:

	输入: [2,3,1,1,4]
	输出: true
	解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
	示例 2:

	输入: [3,2,1,0,4]
	输出: false
	解释: 无论怎样，你总会到达索引为 3 的位置。
	但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

	idea:
	（1）一种 naive 的方法是遍历所以情况，查看是否有满足条件的情况；
		当数组长度很大时，时间复杂度急剧增加，方案不可行
	（2）可以吧整个过程分解，判断从nums【0】到nums【n-1】是否可达，
		依次判断nums【0】到nums【1】是否可达，nums【0】到nums【2】是否可达，
		nums【0】到nums【n-2】是否可达，这其实是一个动态规划过程
*/


class Solution {
public:
    bool canJumpToEnd(vector<int>& nums) {
        bool flag = false;	// nums为空时，默认返回false

        if(nums.size() == 1)
        	flag = true;
        else if(nums.size() > 1){
        	int n = nums.size();
        	int *num_jumps = new int[n];	// num_jumps[i]: "从nums[0]到nums[i]需要的最少跳数"
        									// 当需要计算 从nums[0]到nums[n-1]需要的最少跳数时，只要返回最终的num_jumps[n-1]即可

        	num_jumps[0] = 0;	// 初始化，从nums[0]到nums[0]跳数为0

        	for(int i=1; i<n; i++){
        		num_jumps[i] = INT_MAX;	// 每次进入循环，默认从nums[0]到不了nums[i]，即需要无穷多次jumps

        		for(int j=0; j<i; j++){
        			if(j + nums[j] >= i && num_jumps[j] != INT_MAX){	// 如果这个条件成立，表明nums【j】可达，且从nums【j】可以调到nums【i】
        				num_jumps[i] = min(num_jumps[j] + 1, num_jumps[i]);	// 找到 num_jumps[j]+1 和 num_jumps[i] 中的最小值 
        				break;
        			}
        		}
        	}

        	if(num_jumps[n-1] == INT_MAX)
        		flag = false;
        	else
        		flag = true;
        }

        return flag;
    }

    int min(int a, int b){
    	return a<b?a:b;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {1, 3, 6, 1, 0, 9};
	vector nums(arr,arr + sizeof(arr)/sizeof(int));

	Solution *solu = new Solution();
    bool flag = solu->canJumpToEnd(nums);
    	
    cout << "can it jump from head to end? " << flag << endl;

	return 0;
}