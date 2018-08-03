#include <iostream>
#include <utility>	// pair<data_type1,data_type2>用到
#include <cmath>
#include <string>
using namespace std;

/*
	problem: Excel表列序号
	给定一个Excel表格中的列名称，返回其相应的列序号。

	例如，

	    A -> 1
	    B -> 2
	    C -> 3
	    ...
	    Z -> 26
	    AA -> 27
	    AB -> 28 
	    ...
	示例 1:

	输入: "A"
	输出: 1
	示例 2:

	输入: "AB"
	输出: 28
	示例 3:

	输入: "ZY"
	输出: 701

	idea:
	首先要知道字符串长度，这和最后的编号密切相关，假设字符串长度为n，
	说明由 n-1,n-2,n-3,...,1 个字符组成的编号已经用完，
	因为一个字符串的编码是由前面字符的编码是累加起来的，
	a. 所以先要计算出 n-1,n-2,n-3,...,1位字符总共占用了多少个编码，
	b. 然后计算 长度为n的字符串s 本身占用了多少个编码，
	c. 最后把a和b的结果累加
*/


class Solution {
public:
    int titleToNumber(string s) {        

        int id = 0;	// 记录字符串s对应的（列或行）编号
        			// 如果字符串长度为0，默认返回0

        if(s.length() == 1){
        	char ch = s[0];        	        
        	id = int(ch) - 64;	
        }
        else if(s.length() > 1){        	
	        for(int i=0;i<s.length() - 1;i++){	// 计算长度为 s.length() 的字符串能编多少个编号
	        	char ch = s[i];
	        	int num = int(ch) - 64;	// 转化成大写字母对应的数字        	

	        	id += (num-1) * pow(26, s.length() - (i+1) );
	        }

	        char ch = s[s.length()-1];
	        id += int(ch) - 64;

	        for(int i=1;i<=s.length()-1;i++){ 	// 计算长度为 1,2,...,s.length()-1的字符串能编多少个号
	        	id += i*pow(26, i);
	        }
        }

        return id;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	string s;
	cin >> s;

	Solution *solu = new Solution();
	cout << s << " corresponding COLUMN number " << solu->titleToNumber(s) << endl;

	return 0;
}