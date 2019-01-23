#include <string>
#include <vector>

// ================= problem ================
// 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

// 例如，给出 n = 3，生成结果为：

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

// ================= idea =================
// REFERENCE: https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/
// Keep track of counts of open and close brackets.

// ① Initialize these counts as 0.
// ② Recursively call the _printParenthesis() function until close bracket count is equal to the given n.
//  a. If open bracket count becomes more than the close bracket count, then put a closing bracket and recursively call for the remaining brackets.
//  b. If open bracket count is less than n, then put an opening bracket and call _printParenthesis() for the remaining brackets.

class Solution {
public:
    char str[100];  // 只需要一个公共的char数组，后一种情况覆盖前一种情况即可
    Solution(){
	   	str[2*n] = '\0';    // 设置char数组结束符; 在这里只需设置一次，递归里面 字符数组str 转换成字符串时不用担心没有设置结束符导致出错的问题
    }
    vector<string> generateParenthesis(int n) {
    	vector<string> result;
        printParenthesis(n, result);

        return result;
    }

    void printParenthesis(int n, vector<string> &result){
	    if(n > 0)
	        _printParenthesis(0, n, 0, 0, result);	// 第一个参数：表示生成第n个位置的括号，从第0个位置开始，到第2n-1个位置借宿，总长度为2n
	    	// 第三个参数：左括号的数量
	    	// 第四个参数：右括号的数量
	    return;
    }

    void _printParenthesis(int pos, int n, int open, int close, vector<string> &result){
	     
	    if(close == n) 	// 右括号个数等于n，表示生成了一个满足条件的括号
	    {
	        string s(str);		// 把一个char数组转换成字符串简单有效的方法
	        result.push_back(s);	// 关于向量插入 元素的方法有很多，这里选择push_back，更多方法参考 vector 官方文档
	    }
	    else
	    {
	        if(open > close) 
	        {
	            str[pos] = ')';
	            _printParenthesis(pos+1, n, open, close+1, result);
	        }
	         
	        if(open < n)
	        {
		        str[pos] = '(';
		        _printParenthesis(pos+1, n, open+1, close, result);
	        }
	    }
    }
};