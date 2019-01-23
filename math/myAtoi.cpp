#include<iostream>
#include<vector>
#include<climits>

/*
============= problem =============
实现 atoi，将字符串转为整数。

该函数首先根据需要丢弃任意多的空格字符，直到找到第一个非空格字符为止。如果第一个非空字符是正号或负号，选取该符号，并将其与后面尽可能多的连续的数字组合起来，这部分字符即为整数的值。如果第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

字符串可以在形成整数的字符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。

当字符串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含空白字符时，则不进行转换。

若函数不能执行有效的转换，返回 0。

说明：

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。如果数值超过可表示的范围，则返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

============== idea ==============
这道题关键在理清逻辑，还有判断数值溢出条件
1、去掉空格字符
2、判断正负号
3、开始累加，累加之前要判断数值溢出条件，因为如果先进行累加，可能结果已经溢出了，再判断溢出失去了意义
*/

using namespace std;

class Solution {
public:
    int isWho(char ch){
        if(ch == '+')
            return 0;
        else if(ch == '-')
            return  1;
        else if(ch>='0' && ch <= '9')
            return 2;
        else    //不能转换成整数
            return 3;
    }
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;   //标记正负号
        if(str.length() > 0){
            int i = 0;
            while(i < str.length() && str[i] == ' ')    //过滤空格
                i++;

            if(i < str.length()){
                if(isWho(str[i]) != 3){ //排除不能转换成整数的情况
                    //sign初值为1，默认为正数，如果为负数，变号；
                    // 只有这两种情况执行i++，判断正负号不应该有先后顺序，所以用 || 判断
                    if(isWho(str[i]) == 0 || isWho(str[i]) == 1) {
                        if(isWho(str[i]) == 1)  sign = -sign;
                        i++;
                    }
                    
                    while(i < str.length()){
                        cout << "str[i]: " << str[i] << endl;
                        if(isWho(str[i]) == 2)  //确保str[i]为数字字符
                        {
                            if(res > INT_MAX/10 || (INT_MAX/10 == res && str[i] > '7')){    //溢出条件判断，很关键
                                if(sign > 0)
                                    res = INT_MAX;
                                else
                                    res = INT_MIN;
                                i = str.length();   //结束循环
                            }else{
                                res = 10*res + (str[i++] - '0');
                            }
                        }
                        else break;
                    }
                }
            }
            
        }
        return sign * res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    string str;
    cout<<"input str: ";
    cin>>str;

    Solution *solu = new Solution();
    int res = solu->myAtoi(str);
    cout << "res: " << res << endl;
    return 0;
}
