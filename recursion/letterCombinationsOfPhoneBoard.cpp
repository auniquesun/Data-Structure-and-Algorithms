/*
 * problem: 电话座机的数字与字母键对应关系如 Solution()
 *          输入一个数字串，求所有可能的字符组合
 *          如“23”对应九种组合，"ad" "ae" "af" ...
 *
 * idea：这道题的关键是用递归深入到字符串最后一个位置，
 *       退出的过程中穷尽所有情况
 *       如何设计递归？高明的地方是在每个digit对应的字符串中递归深入
 *
 * */

class Solution {
    unordered_map<char, string> digit2letter;
public:
    Solution(){
        digit2letter['0'] = "";
        digit2letter['1'] = "";
        digit2letter['2'] = "abc";
        digit2letter['3'] = "def";
        digit2letter['4'] = "ghi";
        digit2letter['5'] = "jkl";
        digit2letter['6'] = "mno";
        digit2letter['7'] = "pqrs";
        digit2letter['8'] = "tuv";
        digit2letter['9'] = "wxyz";        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length() == 0)
        	return result;

    	// 过滤掉digits中的0或1
    	string s = "";	
        for(int i=0; i<digits.length(); i++)
        	if(digits[i] != '0' && digits[i] != '1')
        		s += digits[i];    

        // 从digits第一个字符开始扫描
        int cur_idx = 0;    	

        char *letters = new char [digits.length() + 1];	//一种可能的字母组合，初始化为空
        letters[digits.length()] = '\0';

        combineUtil(s, 0, letters, result);	//递归入口, letters 和 result 都是引用传递

        return result;
    }
    void combineUtil(string digits, int cur_idx, char letters[], vector<string> &result){
        if(digits.length() == cur_idx){
        	string str(letters);	//把 char* 转化成 string
            result.push_back(str);
            return;	//找到一个组合，返回
        }

        // digits[cur_idx] 表示扫描到了 digits的哪一位
        // digit2letter[digits[cur_idx]] 表示数字对应的字符串
        // 这个循环遍历字符串中所有的字符，外加递归深入到 digits 最后一位，
        // 再逐层退出，退出的过程中穷尽所有情况
        for(int i=0; i<digit2letter[digits[cur_idx]].length(); i++){
            letters[cur_idx] = digit2letter[digits[cur_idx]][i];
            combineUtil(digits, cur_idx+1, letters, result);
        }
    }
};
