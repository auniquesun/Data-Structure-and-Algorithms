#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

/*
	problem: 两数相除
	给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

	返回被除数 dividend 除以除数 divisor 得到的商。

	示例 1:

	输入: dividend = 10, divisor = 3
	输出: 3
	示例 2:

	输入: dividend = 7, divisor = -3
	输出: -2
	说明:

	被除数和除数均为 32 位有符号整数。
	除数不为 0。
	假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。

	idea:
	整数相除，
	int 型变量，最大值为 2^31 − 1，最小值为 -2^31

	（1）c++ 语法里就不允许除数为 0，所以
	（2）这个题的关键在于判断相除结果是否溢出，什么情况下会溢出呢？
	当除数为 -2^31，被除数为 -1，商为 2^31，则溢出（int 变量表示的最大值为 2^31 − 1）

	其余情况下，只要分母等于1 或者 绝对值大于1，均不会溢出
*/


class Solution {
public:
    int divide(int dividend, int divisor) {
    	if(divisor == 0)
    		return INT_MAX;

    	if(dividend == INT_MIN && divisor == -1)
    		return INT_MAX;

        int num = dividend / divisor;
        return num;
    }
};

int main()
{
    /* code */    
    int dividend;
    int divisor;

    cin >> dividend >> divisor;

    Solution *solu = new Solution();
	cout << dividend << "/" << divisor <<" = " << solu->divide(dividend, divisor) << endl;
    
    return 0;
}