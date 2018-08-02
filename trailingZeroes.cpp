#include<iostream>

using namespace std;

/*
	problem:
	给定一个整数 n，返回 n! 结果尾数中零的数量。

	示例 1:

	输入: 3
	输出: 0
	解释: 3! = 6, 尾数中没有零。
	示例 2:

	输入: 5
	输出: 1
	解释: 5! = 120, 尾数中有 1 个零.
	说明: 你算法的时间复杂度应为 O(log n) 。

	idea:
	(1)	容易想到的方法是 计算出n！，再数末尾包含零的个数，
	但是，这种方法显然不可行，因为 n！很容易上溢出
	通常第一反应想到简单直接的方法，往往不可行

	(2) 计算n！再数零的方法不可行，相当于告诉我不用计算n！，也能得到结果
	分析 "尾数为0的数" 有什么特点：
		a. 尾数为0，这个数的因式分解中肯定包含 2 和 5，
		b. 而且因式中2的个数 >= 5的个数
		c. 每有一对 2和5，尾数就能产生一个 0
		d. 总结以上三点，只要计算 n！ 分解的因式中 "包含几个5"

		但是这么来看，还是要对 n！因式分解，还是要先计算出n！
		有一种简单的方法，不对n！因式分解，就能知道n！包含几个5，

		举例来说：n = 200, n！= 200！
		a. 5（=1*5），10（=2*5），15（3*5），...，200（40*5） 这40个数，因式分解都包含 一个5
		b. 25（=1*5*5），50（=2*5*5），...，200（=8*5*5） 这8个数，因式分解都包含 两个5 (但是已经在上一条 a. 计算过一个，所以只剩一个)
		c. 125（=1*5*5*5） 这1个数，因式分解包含 三个5 (但是已经在上两条 a. b. 计算过两个，所以只剩一个)

		到这里就可以看出规律了：

		Trailing 0s in n! = Count of 5s in prime factors of n!
                  		  = floor(n/5) + floor(n/25) + floor(n/125) + ....

*/

class Solution {
public:
    int trailingZeroes(int n) {
    	int sum = 0;	// 默认为尾数没有0

        for (int i = 5; n/i > 0; i *= 5)
        {
        	/* code */
        	cout << sum << " " << n/i << endl;
        	sum += n/i;

        	if(n/i == 1)	// 当 "第一次" 满足 n/i == 1 时，说明i已经与n是一个数量级，
        					// 如果n很大的话，i下次循环再乘以5，很可能上溢出，i上溢出后变成了一个较小的数
        					// i因为溢出变成较小的数后，导致 n/i 仍然满足 n/i > 0，但实际上 n/i 已经为0了
        					// 所以要在此停止循环
        					// n取1808548329检测到此bug
                break;                  	
        }

        return sum;
    }
};

int main(int argc, char const *argv[])
{
	/* code */

	int n;
	cin >> n;

	Solution *solu = new Solution();

	cout << n << "! has " << solu->trailingZeroes(n) << " trailing zeroes" << endl;

	return 0;
}