#include<iostream>
#include <unordered_set>

using namespace std;

/*
	problem：
	编写一个算法来判断一个数是不是“快乐数”。

	一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

	示例: 

	输入: 19
	输出: true
	解释: 
	12 + 92 = 82
	82 + 22 = 68
	62 + 82 = 100
	12 + 02 + 02 = 1

	idea：
	（1）从上面示例可以看出，判断快乐数的过程中会产生许多中间的数，
	（2）这和判断一个数除以另一个数的结果 是不是 “无限循环小数” 类似，
	当除的过程中重复某些位的循环，则除的结果就是无限循环小数；
	（3）把中间结果存在一个数据结构里，如果再次出现同样的中间结果，则不是快乐数；
		如果有中间结果等于1，则是快乐数
*/

class Solution {
public:
    bool isHappy(int n) {
    	unordered_set<int> S;	


		while(true){			
			n = bitSquareSum(n);	// 计算每位数字平方和; 利用现在的n计算新生成的n，这样才能循环起来

			if(n == 1)	// 快乐数的条件
				return true;
			else if(!S.empty() && S.find(n) != S.end())	// 如果num已经在S中存在，说明循环了一圈，则n不是快乐数
														// 以前的问题是不管else if中的条件是什么，总会返回false，
														// 我就很奇怪了，用gdb调试了好几遍才发现问题，
														// 原来的语句是这样写的，else if(!S.empty() && S.find(n) != S.end());	
														// 分号直接加在了else if()语句的后面
				return false;

			S.insert(n);
		}
    }

    int bitSquareSum(int n){
		int sum = 0;	
		int bit;

		while(n){			
			bit = n % 10;
			n /= 10;

			sum += bit * bit;
		}       

		return sum;
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	Solution *solu = new Solution();

	cout << 19 << " is happy number? " << solu->isHappy(19) << endl;
	return 0;
}
