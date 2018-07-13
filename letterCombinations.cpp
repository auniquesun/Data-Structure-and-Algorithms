#include<iostream>
#include <vector>
#include <string>

using namespace std;

// ===================== problem ====================
// 电话号码的字母组合
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

// 给出数字到字母的映射 ==>（与电话按键相同）。注意 0,1 不对应任何字母。


// ====================== idea ======================
// 想法一：用嵌套的循环解决，当输入字符很长时，需要嵌套许多循环，更重要的一个问题是 --
// 		不可能事先规定好几个循环，需要根据输入字符串的长度变化，naive method

// 想法二：输入digits的每一个digit都对应3或4种可能，例如输入的digits为23
// 		从最后一位digit观察 --
// 		当 d,e,f 遍历一轮后，最后一位前一位的 digit 也要发生变化，才能产生不同的组合，即
// 		① ad,ae,af 遍历完毕; 
// 		② 前一位digit需要变化成b，后一位digit再迭代一轮产生 bd,be,bf
// 		③ 前一位digit再变化成c，后一位digit再迭代一轮产生 cd,ce,cf

// 		这个过程中就包含着 “回溯” 的思想 ==> 可以用递归的方法求解，就这个问题而言：
// 		① 递归入口，vector<string> result，需要引用传递，最后捕获到递归过程中值的变化
// 		② 递归退出的条件：产生一个完整的字母组合，等价于跟踪 位置的指针 指到digits末尾


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;	// 存放最终返回结果
        
        if(digits.length() != 0){   // 只有当 输入的digits 有数字时，才进入递归            
            int cur_index = 0;	// 初值为0，表示从digits第一个字符开始

            int digits_len = digits.length();

            char *word = new char[digits_len + 1];  // 用来存放一种字母组合，字母组合的形成是一个字符一个字符拼接出来的
            word[digits_len] = '\0';    // 最后一位置为 char数组 结束符


            int count = 0;  // 记录有多少种组合情况，下标从0开始，在测试时使用

            combination(digits, cur_index, digits_len, word, result, count);	
        }

        return result;  // 如果输入的字符串为空，则会返回空的 向量result
    }
    
    void combination(string digits, int cur_index, int digits_len, char word[], vector<string> &result, int &count){
    	if(cur_index == digits_len){	// wcur_index 与 digits_len 相等时，表明一种字母组合处理完毕，即找到了一种字母组合
    		string s(word); // 把字符数组转换为string类型
            result.push_back(s);
            cout << count << ": " << word << endl;        	// 测试时使用    
    		count++;
    		return;
    	}

    	string str = digit2str(digits[cur_index]);	// 获取该数字对应的字符串

    	for(int i=0;i<str.length();i++){
    		word[cur_index] = str[i];	// 处理当前位置的字符
    		combination(digits,cur_index+1,digits_len,word,result,count);	// 递归：当前位置处理完，cur_index 移向digit对应的下一种可能
    	}
    }
	
	string digit2str(char digit){	// digit到字符串的映射
		switch(digit){
			case '2': return "abc";
			case '3': return "def";
			case '4': return "ghi";
			case '5': return "jkl";
			case '6': return "mno";
			case '7': return "pqrs";
			case '8': return "tuv";
			case '9': return "wxyz";
			default: return "";	// 处理特殊输入
		}
	}
};

int main(){
	string digits;
	cout<<"input digits: ";
	cin>>digits;

	Solution *solu = new Solution();
	vector<string> result = solu->numIslands(digits);
	
	for(int i=0;i<result.size();i++)
		cout << result[i] << " ";
	cout << endl;

	return 0;
}
