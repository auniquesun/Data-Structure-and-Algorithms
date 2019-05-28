// 真是缘分啊，扫了一眼，就知道这是我想要的题
// 但是从 word break 完全看不出来是这道题啊
// 阿里妈妈面我的一道题，没做出来，当时就挂定了

/*
problem：
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

idea: 很明显的递归思路嘛，不敢说，也不敢写，肯定悲剧了
*/
class Solution {
public:
    bool contain(string s, vector<string>& wordDict){
        for(int i=0; i<wordDict.size(); i++)
            if(s == wordDict[i])
                return true;
        return false;
    }

    // solution 1，这种方法时间复杂度太高
    bool wordBreak1(string s, vector<string>& wordDict) {
        if(s.size() == 0)
            return true;

        for(int i=1; i<=s.size(); i++){
            // 说实话看到了递归的实现都觉得简单，但是想的时候想不出来
            // string.substr(i, j) 第一个参数表示子串起始位置，第二个参数表示子串长度
            if(contain(s.substr(0, i), wordDict) && wordBreak(s.substr(i, s.size() - i), wordDict))
                return true;
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0)
            return true;
        
        // 一个关键的数组，flags[i]只有两个取值，0或1;
        // 1表示s[0...i-1]能够与 wordDict 中的字符串匹配
        int flags[s.size() + 1] = {0};    // 全部初始化为0
        for(int i=1; i<=s.size(); i++){
            if(flags[i] == 0 && contain(s.substr(0, i), wordDict))
                flags[i] = 1;
                        
            if(flags[i] == 1){
                if(i == s.size())
                    return true;

                for(int j=i+1; j<=s.size(); j++){
                    if(flags[j] == 0 && contain(s.substr(i, j-i), wordDict))
                        flags[j] = 1;
                    if(flags[j] == 1 && j == s.size())
                        return true;
                }
            }
        }

        return false;
    }
};