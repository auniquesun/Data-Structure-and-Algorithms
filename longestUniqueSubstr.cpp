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
    ~charList(){
    	delete [] node;
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

        if(cl->node[ch2idx].visited == 0){  //情况一：前面的字符串没出现过这个字符
            cur_len++;
            cur_end_pos++;

            cl->node[ch2idx].visited = 1;   //把当前扫描过的字符标记为visited
        }else{   //情况二：前面的字符串出现过这个字符，还分为两种小情况
            	   //小情况一：当前子字符串包含此字符

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
}