/*
problem:
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

idea:
O(n)的时间复杂度，肯定只能扫一遍或常数遍
用一个map记录 pattern 串中每个字符出现的次数
用另一个map记录 source 串当前窗口中每个字符出现的次数，
    扫描source，比较与 pattern 中的字符匹配个数
    a. 如果全部匹配上，判断当前窗口能否缩的更小，即窗口左端点右移，右端点不变
    b. 如果没全匹配上，当前窗口右端点右移，左端点不变
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";

        int source_ch2count[256] = {0};
        int target_ch2count[256] = {0};

        for(int i=0; i<t.length(); i++)
            target_ch2count[t[i]]++;

        int start = 0;  // 最小窗口开始位置，从0开始循环
        int start_index = -1; // 记录最小窗口开始位置
        int min_len = INT_MAX;  // 记录最小窗口长度

        int count = 0;  // 记录source当前窗口与pattern中字符匹配了几个
        for(int i=0; i<s.length(); i++){
            source_ch2count[s[i]]++;

            if(target_ch2count[s[i]] !=0 && source_ch2count[s[i]] <= target_ch2count[s[i]])
                count++;

            if(count == t.length()){    // 表明全部匹配上
                // 对应的字符 s[start] 比 target_ch2count[s[start]]多，
                // target_ch2count[s[start]]为0，表明 s[start] 在窗口中是多余的
                while(source_ch2count[s[start]] > target_ch2count[s[start]] || target_ch2count[s[start]] == 0)
                {
                    if(source_ch2count[s[start]] > target_ch2count[s[start]])
                        source_ch2count[s[start]]--;
                    start++;
                }

                int cur_len = i - start + 1;
                if(cur_len < min_len){
                    start_index = start;
                    min_len = cur_len;
                }
            }
        }

        if(start_index == -1)
            return "";
        else return s.substr(start_index, min_len);
    }
};