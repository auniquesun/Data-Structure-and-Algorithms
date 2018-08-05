#include <iostream>

using namespace std;

/*
	problem: 两整数之和
	不使用运算符 + 和-，计算两整数a 、b之和。

	示例：
	若 a = 1 ，b = 2，返回 3。

	idea:
	不能使用 + 号，有两种可行的方法：
	（1）模拟加法计算过程，
		从个位数算起，对a和b对应的bit逐一作判断，两个对应的bit位相加结果存在两个变量里 
			-- carry，存储进位
			-- sum，存储两个bits之和

		把每位计算结果存在字符串里，最后字符串转化为整型变量返回

	（2）方法（1）是一种可行的方法，但是需要许多 if 语句作判断，每位取值有10种可能，
		则对应的一对 bit 位有100种可能；可以利用 c++ 位运算解决这道题：
		a. 两个数 按位与 &，得到的结果 "标记了哪些位相加时有进位" -- 自己可以举例子验证
		b. 两个数 按位异或 ^，得到的结果是 "两数去掉进位按位相加的结果" -- 自己可以举例子验证

		注意：位运算时，c++默认把十进制转为二进制进行计算，但是计算得到的结果以十进制表示
*/

class Solution {
public:
    int getSum(int a, int b) {
    	int count = 0;
        while(b != 0){
                // cout << " ========== " << count++ << " ========== " << endl;

                int carry = a & b;
                // cout << "carry: " << carry << endl;

                a = a^b;
                // cout << "a: " << a <<endl;

                b = carry << 1;
                // cout << "b: " << b << endl;
        }

        // cout << "result: " << a << endl;
        return a;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	int a,b;
	cin >> a >> b;

	Solution *solu = new Solution();
	cout << "sum of " a << "and" << "b: " << solu->getSum(a, b) << endl;

	return 0;
}