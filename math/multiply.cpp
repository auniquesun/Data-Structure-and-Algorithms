#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm> // reverse包含在这里面

using namespace std;

/*
problem: 字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

idea:
用字符串来处理整数乘法，并且返回字符串结果，避免数值溢出问题
整体的思想就是模拟乘法的计算过程：
1. num1表示被乘数，num2表示乘数，
2. 用乘数的每一位与被乘数相乘，得到一个结果
3. 对结果进行移位操作，存到一个 vector 里
4. 对 vector 中所有数相加
    注意进位，reverse，取0等细节
*/

class Solution {
public:
    char digit2char(int n){ //可以用 itoa 函数来解决，包含在 <cstdlib>
        char ch[] = {'0','1','2','3','4','5','6','7','8','9'};
        if(n>=0&&n<=9)
            return ch[n];
        else{
            cout << "error" << endl;
            return ' ';
        }
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
            
        //默认num1的长度大于等于num2，如果不符合则交换
        if(num1.length()<num2.length()){
            string tmp;
            tmp = num1;
            num1 = num2;
            num2 = tmp;
        }

        vector<string> nums;
        int max_len = 0;    //记录数组中哪个数的位数最长，为最终各个数相加作准备
        for(int i=num2.length()-1, k=num2.length()-1;i>=0;i--){//外层循环遍历num2，从后向前
            string str="";
            int carry = 0;  //进位初始化为0
            for(int j=num1.length()-1;j>=0;j--){
                int num = (num2[i]-'0') * (num1[j]-'0') + carry;    //对应位的乘积
                int val = num%10;   //乘积上的个位数
                carry = num/10; //进位
                
                str += digit2char(val);
            }
            if(carry != 0)  //如果进位不为0，还有补上进位
                str += digit2char(carry);
            //需要reverse的原因是：str是累加产生的，
            // 先计算得到的个位数排到了最前面，最后计算出来的高位数排在了最后；下同
            reverse(str.begin(), str.end());
            
            cout << "== " << i << endl;
            cout << "before: " << str << endl;
            for(int m=0;m<k-i;m++)  //为str后面补0
                str += "0";
            cout << "after: " << str << endl;
            
            if(str.length()>max_len)
                max_len = str.length();
            nums.push_back(str);
        }
       
        string res="";  //初始化最终结果
        int carry = 0;  //初始化进位
        
        for(int i=0;i<max_len;i++){ //扫描一个数中的每一位
            int num = 0;    //nums中所有数对应位digit的和           
            for(int j=0;j<nums.size();j++){
                int index = nums[j].length() - 1 - i;   //digit相加，从个位数到十位数的方向加起                
                if(index>=0)                    
                    num += nums[j][index] - '0';    //**注意: nums[j][index]是字符，减掉'0'才转换成数字**                                
            }
            num += carry;   //digit相加完，再加上进位
            
            int val = num%10;   //取余剩下个位数
            carry = num/10; //重新计算进位

            res += digit2char(val);            
        }
        if(carry != 0)  //如果进位不为0，还有补上进位
                res += digit2char(carry);
        reverse(res.begin(), res.end());    //返回类型为void
        return res;
    }    
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution *solu = new Solution();
    string num1,num2;
    cout << "input num1, num2: " ;
    cin >> num1 >> num2;
    string res = solu->multiply(num1, num2);

    cout << "res: " << res << endl;
    return 0;
}
