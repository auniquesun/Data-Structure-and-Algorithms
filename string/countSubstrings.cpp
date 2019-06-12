/*
problem:
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.

idea:
这道题是求一个字符串中，回文子串的个数，看上去就不会做了，不应该
之前做过一道题，是求一个字符串中的最长回文子串，
因为最长回文子串求解过程中，必然要知道每个回文子串的长度，最后取最长的，
能知道每个回文子串的长度，再用一个计数器，不就能知道回文子串的个数？
*/

class Solution {
public:
    // solution one，时间复杂度 O(n2)，空间复杂度 O(1)
    int countSubstrings(string s) {
        int count = 0;
        int low, high;
        if(s.length()){
            // 因为字符串的每个字符，都可以算作一个回文子串，所以初始化为字符串长度
            count = s.length();

            // 奇数长度的回文串个数，并且回文子串长度>=3
            for(int i=1; i<s.length()-1; i++){
                low = i-1;
                high = i+1;
                while(low >= 0 && high<s.length() && s[low] == s[high]){
                    low--;
                    high++;
                    count++;
                }
            }

            // 偶数长度的回文串个数
            for(int i=0; i<s.length()-1; i++){
                low = i;
                high = i+1;
                while(low >= 0 && high<s.length() && s[low] == s[high]){
                    low--;
                    high++;
                    count++;
                }
            }
        }
        return count;
    }
};