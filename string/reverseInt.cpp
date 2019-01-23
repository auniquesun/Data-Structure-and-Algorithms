#include<stack>
#include<cmath>
#include<iostream>
#include<climits>
using namespace std;

/*
problem：整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

idea:
思路很简单，关键在于判断逆转后的值是否溢出，因为INT表示的值大小有限
*/
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)    //INT_MIN的绝对值会溢出，直接返回
            return 0;

        int num = abs(x);   //都按照整数计算，负号另外考虑
        cout << "num: " << num << endl;

        int sign = 1;   //记录x的正负号，默认为正
        if(x<0)
            sign = -1;

        stack<int> st;
        do{
            st.push(num%10);
            num /= 10;
        }while(num);

        int y = 0;
        int bit = 0;
        while(!st.empty()){
            int val = st.top();
            y += val * pow(10, bit);
            cout << y << endl;
            st.pop();
            bit++;
            cout << "bit: " << bit << endl;
            if(!st.empty()) //逆转后溢出
            {
                if(bit == 9){
                    cout << "st.top(): " << st.top() << endl;
                    if(st.top() >= 3){
                        return 0;
                    }
                    if(st.top() == 2){
                        if(INT_MAX - 2*pow(10,9) < y){
                            return 0;
                        }
                    }
                }
            }
        }

        return sign*y;
    }
};

int main(){
    int n;
    cout << "n: " ;
    cin>>n;
    Solution *solu = new Solution();
    int res = solu->reverse(n);
    cout << res << endl;
}