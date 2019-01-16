#include<iostream>
#include <vector>
#include <climits>

using namespace std;

/*
	problem: 零钱兑换
	给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

	示例 1:

	输入: coins = [1, 2, 5], amount = 11
	输出: 3 
	解释: 11 = 5 + 5 + 1
	示例 2:

	输入: coins = [2], amount = 3
	输出: -1
	说明:
	你可以认为每种硬币的数量是无限的。

	idea:
	动态规划的思想，要想得到金额为amount的硬币的最少个数，
	就要知道金额为 amount-1 时硬币的最少个数，直至递推到 amount 为0，
	下面代码中关键要理解 num_changes[amount + 1] 这个数组存储的元素的含义，
	它包含着动态规划的思想，是从num_changes[0]递推得到num_changes[amount]的
*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 0)
        	return -1;
        if(amount == 0)
        	return 0;
        if(coins.size() == 0)
        	return -1;

        sort(coins.begin(), coins.end());	// 对coins里的币值排序
        int num_changes[amount + 1];	// num_changes【i】表示当amount==i时，组合成amount需要的最少change数

        for (int i = 0; i <= amount; ++i)	// 初始化 数组num_changes
        									// num_changes[0] = 0 是很自然的事情，因为此时amount==0，不需要任何change组合
        {
        	/* code */
        	if(i == 0)
        		num_changes[i] = 0;	
        	else
        		num_changes[i] = amount + 1;
        }

        for (int i = 1; i <= amount; ++i)	// 从1元循环到amount元，假设用“元”作计价单位
        {
        	/* code */
        	for (int j = 0; j < coins.size(); ++j)
        	{
        		/* code */
        		if(coins[j] <= i)		// 对于币值小于i的情况
        			num_changes[i] = min(num_changes[i], num_changes[(i - coins[j])] + 1);	// 动态规划的思想
        																					// 从 i - coins[j] 这么多钱 增到 i 这么多钱，只需"增加一张 -- 对应加1操作"面值为 coins【j】的票子
        																					// 取 num_changes[i] 和 num_changes[(i - coins[j])] + 1 中的最小值
        	}
        }

        return (num_changes[amount] > amount) ? -1 : num_changes[amount];	// coins数组里都为正整数，最小为1，所以num_changes[amount]的最大值为amount
        																	// 如果num_changes[amount]最终取值比 amount 还大，说明它还是初始化的 amount + 1 值，即用coins给定的面值凑不出amount这么多钱
    }

    int min(int a, int b){
    	return a<b?a:b;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	int coins[] = {1, 2, 5};
	vector nums(coins,coins + sizeof(coins)/sizeof(int));

	int amount;
	cin>>amount;

	Solution *solu = new Solution();
    int num = solu->coinChange(nums, amount);
    	
    cout << "least number of coins consisting of amount: " << num << endl;

	return 0;
}