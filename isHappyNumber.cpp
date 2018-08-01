#include<iostream>
#include <unordered_set>
// #include <set>

using namespace std;

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
