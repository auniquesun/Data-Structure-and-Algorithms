#include<iostream>
#include<vector>
#include<climits>

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
