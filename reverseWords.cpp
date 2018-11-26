#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    void reverse(string &substr){   //leetcode不让用c++自带的<algorithm>库
        int len = substr.length() / 2;
        for(int i=0;i<len;i++){
            char ch = substr[i];
            substr[i] = substr[substr.length() - 1 -i];
            substr[substr.length() - 1 -i] = ch;
        }
    }

    string reverseWords(string s) {
        string res = "";
        string substr = "";
        for(int i=0;i<s.length();i++){            
            if(s[i]!=' ')
                substr += s[i];
            else{
                reverse(substr);
                res += substr + ' ';
                substr = "";
            }
        }
        // 如果 s 这个字符串非空，并且它的最后一个字符不是空格
        // 需要把最后一个单词逆转，并加入res
        if(s.length() > 0 && s[s.length() - 1]!=' '){
            reverse(substr);
            res += substr;
        }

        return res;        
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution *solu = new Solution();
    string res = solu->reverseWords("Let's take LeetCode contest");
    cout << "res: " << res << endl;
    return 0;
}
