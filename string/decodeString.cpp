/*
problem:
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

idea:
这个题啊，提供了一种重要的思想，
    “如何寻找一个表达式中最深层的括号”——用栈这种数据结构
    碰到第一个闭括号，意味着找到了最深层的括号，
    第一个闭括号必然对应最后一个开括号
*/

class Solution {
public:
    string decodeString(string s) {
        string result = "";
        if(s.length() > 0){
            stack<int> nums;
            stack<char> chars;

            int num;
            string tmp, substr;
            for(int i=0; i<s.length(); ){
                if(s[i] >= '0' && s[i] <='9'){
                    num = 0;
                    while(s[i] >= '0' && s[i] <='9'){   // 有可能是一连串的数字，但是只算做一个数
                        num = 10*num + (s[i] - '0');
                        i++;
                    }
                    nums.push(num);
                }
                else if(s[i] == '['){
                    if(i==0 || i>=1 && !(s[i-1] >= '0' && s[i-1] <='9'))  // '['前面的不是数字
                        nums.push(1);   // 数字栈中要放入 1
                    chars.push(s[i]);
                    i++;
                }
                else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                    chars.push(s[i]);
                    i++;
                }
                else if(s[i] == ']'){
                    if(!nums.empty()){  // 找到了当前chars的第一个闭括号，弹出数字，开始解码
                        num = nums.top();
                        nums.pop();
                    }

                    substr = "";
                    while(!chars.empty() && chars.top() != '['){    // 可能是多个连续字母，用循环
                        
                        substr += chars.top();
                        chars.pop();
                    }
                    cout << "substr: " << substr << endl;

                    if(!chars.empty() && chars.top() == '[')     // 遇到一个 ']'，弹出一个 '[' 即可
                        chars.pop();

                    tmp = "";
                    for(int j=0; j<num; j++)    // 解码 num 次
                        tmp += substr;
                    cout << "tmp: " << tmp << endl;

                    for(int j=tmp.length()-1; j>=0; j--){   // 把本次解码的结果再次压入字符栈，因为下次解码依赖本次解码的结果
                        chars.push(tmp[j]);
                    }

                    i++;    // 别忘了让扫描 s 的索引前进
                }
                else{
                    cout << "unexpected char occurrs in input s" << endl;
                    break;
                }
            }

            while(!chars.empty()){
                result += chars.top();
                chars.pop();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};