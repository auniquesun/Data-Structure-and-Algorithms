/*
problem: 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

idea:
这个问题看上去比较复杂，不仅要看括号成不成对，还要看前后顺序对不对
实际上用“栈”结构做很简单 --
    遇到开始符入栈，遇到结束符出栈，循环结束时，如果栈为空，则表示输入是有效的括号对
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        set<char> start;    start.insert('{'), start.insert('('), start.insert('[');
        set<char> end;      end.insert('}'), end.insert(')'), end.insert(']');

        set<char>::iterator it;     //集合元素的迭代器

        map<char, char> end2start;  //结束字符到开始字符的映射
        end2start['}'] = '{';
        end2start[')'] = '(';
        end2start[']'] = '[';

        for(int i=0;i<s.length();i++){
            it = start.find(s[i]);
            if(it != start.end())   //扫面到的字符是开始字符，入栈
                st.push(s[i]);
            else    //扫面到的字符是结束字符
            {
                if(!st.empty()){
                    char ch = st.top();
                    if(ch == end2start[s[i]])     //开始字符与结束字符匹配上，并且栈非空
                        st.pop();
                    else return false;    //结束循环
                }
                else return false;    //栈为空，并且遇到结束字符，结束循环
            }
        }

        if(st.empty())  //退出循环，st为空
            return true;    //能执行到这里，表示输入的s是有效的括号组合
        else return false;
    }
};