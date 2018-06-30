// ============== idea with linear time ==============

// for loop
// 1 从左到右扫描字符串，
// 2 跟踪当前子字符串的长度，cur_len
// 3 记录所有处理过的子字符串的最大长度 max_len
// 4 对于一个将要扫描的字符，有两种情况：
//     ①如果这个字符在当前子串中没有出现，更新当前子串结束位置，同时更新当前子串长度
//     ②如果这个字符在当前子串中出现过（注意这里我并不关心它在当前子串之前的子串里是否出现），更新当前子串的开始位置和结束位置，同时更新当前子串的长度;如果这个字符在当前子串中没有出现，但是在当前子串之前的子串里出现，cur_len++, cur_end_pos++
// 5 比较 cur_len 与 max_len，
//     if cur_len > max_len
//         max_len = cur_len

// 不能默认输入的字符都是英文大小写，可以是各种各样的字符，
// 以前的解法（默认输入只有英文大小写字符）存在严重错误

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

    cout<<"===================================="<<endl;
    cout<<"input a string: ";
    string s;
    cin>>s;

    set<char> char_set;

    int n = s.length();
    if(n == 0)  //不可以默认最大长度为1，因为可能输入空字串
        return 0;
    else{
        int i,j;
        int max_len=1,cur_len=1;    

        int cur_start_pos = 0; //当前子串的起始位置
        int cur_end_pos = 0;  //当前子串的结束位置

        char ch;    //存储当前字符

        ch = s[0];
        char_set.insert(ch);

        for(i = 1;i < n;i++){
            ch = s[i];

            if(char_set.find(ch) == char_set.end()){
                cur_len++;
                cur_end_pos++;

                char_set.insert(ch);
            }else{
                int flag = 1;   //假设：当前子串内包含当前字符ch
                for(j = cur_start_pos;j <= cur_end_pos;j++){
                    if(s[j] == s[i]){   //①如果假设成立，进行处理
                        cur_start_pos = j+1;    //重新定位新子串的开始位置, 出现过此字符的位置加1
                        cur_end_pos = i;    //重新定位新子串的结束位置
                        cur_len = cur_end_pos - cur_start_pos + 1;    //重新记录新子串的长度
                        flag = 0;       //改变标志位
                        j = cur_end_pos;    //退出for循环
                    }
                }

                if(flag){    //小情况二：当前子字符串不包含此字符
                                //②如果假设不成立，标志位没有改变，flag == 1
                    cur_len++;
                    cur_end_pos++;
                }
            }

            if(max_len < cur_len)
                max_len = cur_len;            

        }

        cout << "the length of longest unique substr is: " << max_len <<endl;
        cout<<"===================================="<<endl;

        return max_len;
    }
}
