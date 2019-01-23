#include<iostream>
#include<climits>
using namespace std;

/*
problem:
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16
示例 3:

输入: 218
输出: false

idea:
既然是幂次方问题，
把num初值设为1，不断用num乘2，如果能得到n，就表明符合要求；注意判断整数溢出问题
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        if(n==1)
            return true;

        int num = 1;
        int num_prev = 1;
        while(num<=n){
            num *= 2;
            if(num < num_prev)  //表明num数值溢出，这个题的关键是要判断这一点
                break;
            else
                num_prev = num;

            cout << "num: " << num << endl;
            if(num == n)
                return true;
        }

        return false;
    }
};

int main(){
    int n;
    cout << "number n: " ;
    cin>>n;
    Solution *solu = new Solution();
    int res = solu->isPowerOfTwo(n);
    cout << res << endl;
}