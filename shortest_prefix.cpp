#include <iostream>
#include <vector>
using namespace std;

#define MAX 26

struct TrieNode{
    // 有几个字符串公用这个字符
    int count;
    TrieNode *next[MAX];
    TrieNode(){
        count = 0;
        for(int i = 0;i < MAX;++i){
            next[i] = NULL;
        }//for
    }
};
// 插入
void Insert(TrieNode* &root,string str){
    int size = str.size();
    if(size == 0){
        return;
    }//if
    TrieNode *p = root;
    int val;
    for(int i = 0;i < size;++i){
        val = str[i] - 'a';
        if(p->next[val] == NULL){
            p->next[val] = new TrieNode();
        }//if
        // 统计共有几个字符串共用该字符
        p->next[val]->count++;
        p = p->next[val];
    }//for
}//Insert
// 字符串的唯一前缀表示
string OnlyPrefix(TrieNode* root,string str){
    int size = str.size();
    TrieNode *p = root;
    int index = 0,val;
    for(int i = 0;i < size;++i){
        val = str[i] - 'a';
        index++;
        p = p->next[val];
        if(p->count == 1){
            break;
        }//if
    }//for
    return str.substr(0,index);
}
// 所有字符串的唯一前缀表示
vector< pair<string,string> > AllOnlyPrefix(vector<string> strs){
    int size = strs.size();
    pair<string,string> prefix;
    vector<pair<string,string> > vec;
    if(size <= 0){
        return vec;
    }//if
    TrieNode *root = new TrieNode();
    // 创建字典树
    for(int i = 0;i < size;++i){
        Insert(root,strs[i]);
    }//for
    // 唯一前缀
    for(int i = 0;i < size;++i){
        prefix.first = strs[i];
        prefix.second = OnlyPrefix(root,strs[i]);
        vec.push_back(prefix);
    }//for
    return vec;
}

int main() {
    vector<string> strs;

    int N;
    cin >> N;
    string str;
    for(int i=0; i<N; i++){
        cin >> str;
        strs.push_back(str);
    }
    
    vector< pair<string,string> > vec = AllOnlyPrefix(strs);
    
    for(int i = 0;i < vec.size();++i){
        pair<string,string> pair = vec[i];
        cout<<pair.second<<endl;
    }//for
}