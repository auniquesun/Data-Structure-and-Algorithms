#include <iostream>
#include <string>

using namespace std;

struct Node
{
	char ch;
	int visited;
};

class charList{	//构建一张 (char) ==> (visited) 的映射表 	存放：大写字母A~Z,小写字母a~z；是否在substr出现过,用visited标记；认为大小写字母不一样
public:
    Node *node = NULL;
    charList(){
        node = new Node[52];
        for(int i=0;i<52;i++){
            if(i < 26){
                node[i].ch = char(65+i);
            }
            else
                node[i].ch = char(97 - 26 + i);

            node[i].visited = 0;    //0 代表没有访问过
        }
    }
};

int main() {

    charList *cl = new charList();
    cout<<"===================================="<<endl;
    cout<<"input a string: ";
    string s;
    cin>>s;

    int n = s.length();

    int i,j;
    int max_len=1,cur_len=1;

    int cur_start_pos = 0; //当前子串的起始位置
    int cur_end_pos = 0;  //当前子串的结束位置

    char ch;    //存储当前字符
    int ch2idx; //把当前字符转换成charList中的索引

    ch = s[0];
    ch2idx = int(ch);

    if(ch2idx >= 65 && ch2idx <= 90)
        ch2idx -= 65;
    else if(ch2idx >=97 && ch2idx <= 122)
        ch2idx = ch2idx - 97 + 26;

    cl->node[ch2idx].visited = 1;

    for(i = 1;i < n;i++){
        ch = s[i];
        ch2idx = int(ch);

        if(ch2idx >= 65 && ch2idx <= 90)
            ch2idx -= 65;
        else if(ch2idx >=97 && ch2idx <= 122)
            ch2idx = ch2idx - 97 + 26;

        if(cl->node[ch2idx].visited == 0){
            cur_len++;
            cur_end_pos++;

            cl->node[ch2idx].visited = 1;   //把当前扫描过的字符标记为visited
        }else{            
            
            int flag = 1;   //假设：当前子串内包含当前字符ch
            for(j = cur_start_pos;j <= cur_end_pos;j++){
                if(s[j] == s[i]){   //①如果假设成立，进行处理
                    cur_start_pos += 1;    //重新定位新子串的开始位置
                    cur_end_pos = cur_start_pos;    //重新定位新子串的结束位置
                    i = cur_end_pos;
                    cur_len = 1;    //重新记录新子串的长度
                    flag = 0;       //改变标志位
                    j = cur_end_pos;    //退出for循环
                }
            }

            if(flag){    //②如果假设不成立，标志位没有改变，flag == 1
                cur_len++;
                cur_end_pos++;
            }
        }

        if(max_len < cur_len)
            max_len = cur_len;            

    }

    cout << "the length of longest unique substr is: " << max_len <<endl;
    cout<<"===================================="<<endl;
}
