#include <iostream>
#include <cmath>

using namespace std;

/*
	problem:
	实现 pow(x, n) ，即计算 x 的 n 次幂函数。

	示例 1:

	输入: 2.00000, 10
	输出: 1024.00000
	示例 2:

	输入: 2.10000, 3
	输出: 9.26100
	示例 3:

	输入: 2.00000, -2
	输出: 0.25000
	解释: 2-2 = 1/22 = 1/4 = 0.25
	说明:

	-100.0 < x < 100.0
	n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

	idea:
	计算 x 的 n 次幂函数，如果x，n取值很大，结果很容易溢出；
	本来认为 c++ 提供的库函数也不能计算出 pow(99,30) 这样的结果，
	经过测试，<cmath> 是能计算出结果的，而且是正确的；
	说明写这个库函数的开发者想到了溢出的情况，并且作了处理；
	既然有这个写好的方法，直接用好了
*/

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n);
    }
};

int main()
{
    /* code */
    double x;
    int n;
    cin >> x >> n;
    Solution *solu = new Solution();
	cout << "pow(" << x <<"," << n <<") = " << solu->myPow(x, n) << endl;
    
    return 0;
}