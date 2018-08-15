#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

/*
	problem: 逆波兰表达式求值
	根据逆波兰表示法，求表达式的值。

	有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

	说明：

	整数除法只保留整数部分。
	给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
	示例 1：

	输入: ["2", "1", "+", "3", "*"]
	输出: 9
	解释: ((2 + 1) * 3) = 9
	示例 2：

	输入: ["4", "13", "5", "/", "+"]
	输出: 6
	解释: (4 + (13 / 5)) = 6
	示例 3：

	输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
	输出: 22
	解释: 
	  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
	= ((10 * (6 / (12 * -11))) + 17) + 5
	= ((10 * (6 / -132)) + 17) + 5
	= ((10 * 0) + 17) + 5
	= (0 + 17) + 5
	= 17 + 5
	= 22

	idea:
	这道题关键是要搞清楚什么是 -- 逆波兰式，
	直观的说，逆波兰式就是 "后缀表达式"，即运算符写在操作数之后

	（1）因为操作数在前面，开始并不知道要做哪种运算，需要先把操作数存起来
	（2）很容易想到用栈这种数据结构，遇到 运算符 就弹出两个操作数，其他情况把 操作数入栈
	 
	需要注意的是： 加法乘法，弹出的两个数谁在前谁在后，对结果没有影响
					减法和除法，先出栈的为减数或者除数，后出栈的为被减数或者被除数，要作区分
*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // stack<string> stack_operator;	// 存放操作符    ※ 经过后续验证，不需要这个栈也能解决问题 ※
		stack<string> stack_operNum;	// 存放操作数

		// stack_operator.push("#");	// 不需要这个栈了

		for(int i=0;i<tokens.size();i++){
			if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
				string str1 = stack_operNum.top();	// 加法和乘法，两个数谁在前谁在后，对结果没有影响
				stack_operNum.pop();
				string str2 = stack_operNum.top();	// 减法和除法就不一样了，先出栈的（str1）为减数或者除数，后出栈的（str2）为被减数或者被除数
				stack_operNum.pop();

				int num1 = atoi(str1.c_str());
				int num2 = atoi(str2.c_str());

				int result = compute(tokens[i], num2, num1);	// 传参的时候要注意num2，num1的先后顺序

				stack_operNum.push(to_string(result));
			}
			else{
				stack_operNum.push(tokens[i]);
			}

		}	
		string str = stack_operNum.top();
		stack_operNum.pop();

		int result = atoi(str.c_str());
		return result;
    }
    
    int compute(string oper, int num2, int num1){   // 抽象出来一个计算加减乘除的功能
        int index;
        
        if(oper == "+")
            index = 0;
        if(oper == "-")
            index = 1;
        if(oper == "*")
            index = 2;
        if(oper == "/")
            index = 3;
        
    	switch(index){
    		case 0: return num2 + num1;
    		case 1: return num2 - num1;
    		case 2: return num2 * num1;
    		case 3: return num2 / num1;
    	}
    }
};

int main(){
	vector<string> tokens;
	string token;
	while(cin>>token && token != "#"){
		tokenso.push_back(token);
	}

	Solution *solu = new Solution();
	int result = solu->evalRPN(tokens);

	cout << "the value of Reverse Polish Notation " << tokens << " is: " << result << endl;
}