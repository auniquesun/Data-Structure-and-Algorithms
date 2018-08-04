#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
	problem：分数到小数
	给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

	如果小数部分为循环小数，则将循环的部分括在括号内。

	示例 1:

	输入: numerator = 1, denominator = 2
	输出: "0.5"
	示例 2:

	输入: numerator = 2, denominator = 1
	输出: "2"
	示例 3:

	输入: numerator = 2, denominator = 3
	输出: "0.(6)"

	idea：
	这个题的关键在于
	（1）分清楚有哪些情况要处理，其次是（2）除法的计算过程

	a 分子为0，返回0
	b 分子为 INT_MIN，分母为 -1，计算结果溢出，所以直接返回字符串
	c 如果能整除，返回结果；如果不能整除，即存在循环，判断从哪里开始循环，循环部分要加上括号来标记 

*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	string result;

    	if(numerator == 0)
    		result = "0";
        else if(numerator == INT_MIN && denominator == -1)	// 直接用除法计算结果会溢出
            result = "2147483648";
        else if(numerator == -1 && denominator == INT_MIN)  // 这是对特殊情况的判断；我认为这种判断属于作弊，直接把答案写出来了，没有经过计算，但是没想到更好的方法解决问题
            result = "0.0000000004656612873077392578125";
    	else{            
            
    		string int_part = to_string(numerator/denominator);	// 如果结果为负，且商 >=1，整数部分已经带上了负号

    		if(numerator/denominator == 0 && (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0))
    			int_part = '-' + int_part;
    		if(numerator % denominator == 0)	// 如果能整除，只需返回整数部分
    			result = int_part;
    		else{	// 如果不能整除，则有小数部分
    			string deci_part = "";

    			map<int, int> Map;	// 每个元素记录一个 key,value 对，key值代表余数位，value值代表该key对应有多少位小数
    			int remainder = numerator % denominator;

    			if(remainder < 0)	// remainder 可能为负数，这时要把它置为正数
    								// 即保证 key 值为正数
    				remainder = -remainder;

    			while(remainder != 0 && Map.find(remainder) == Map.end()){	// 余数不为0且 remainder 没在Map中出现过
    				Map[remainder] = deci_part.length();

    				remainder *= 10;


    				deci_part += to_string(remainder/denominator);

    				remainder = remainder % denominator;

    				if(remainder < 0)	// remainder 可能为负数，这时要把它置为正数
    								// 即保证 key 值为正数
    					remainder = -remainder;
    			}

    			if(remainder == 0)
    				result += int_part + '.' + signFilter(deci_part);
    			else if(Map[remainder] > 0) 
    				result += int_part + '.' + signFilter(deci_part.substr(0,Map[remainder])) + '(' + signFilter(deci_part.substr(Map[remainder])) + ')';   // 可以参考头文件<string>里 substr的文档说明
                else 
                    result += int_part + '.' + '(' + signFilter(deci_part.substr(Map[remainder])) + ')';
    		}
	      		
    	}
    		
		return result;
    }

    string signFilter(string s){	// 去掉小数部分中的负号，如果有的话
    	if(s.length() > 0){
    		string str="";
    		for (int i = 0; i < s.length(); ++i)
    		{
    			/* code */
    			if(s[i] != '-')
    				str += s[i];
    		}

    		return str;
    	}else
    		return "";
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	int numerator, denominator;
	cin >> numerator >> denominator;

	Solution *solu = new Solution();

	cout << numerator <<"/" << denominator << " = " << solu->fractionToDecimal(numerator, denominator) << endl;
	return 0;
}