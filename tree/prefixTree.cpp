/*
problem:
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

idea:
这个题呀，用到了很精妙的数据结构，结构体数组，数组中的每个元素都是指针类型的
    并且采用了 时间->换空间的做法
    insert, search, startswith 要快
    linux 命令行常见这种，确实很有用
*/
struct TrieNode{
    vector<TrieNode*> children (26, NULL);    // 记录出现了哪个字母
    int isEndOfWord = 0;    // 默认TrieNode不是末尾
};

class Trie {
    TrieNode * tNodeHead = NULL;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        // 就是为了得到 prefix tree 的根节点
        tNodeHead = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *tCrawl = tNodeHead;   //tNodeHead 必不为空，因为使用一个类，先要调用它的构造函数
        for(int i=0; i<word.length(); i++){
            int idx = word[i] - 'a';
            if(tCrawl && !tCrawl->children[idx])
                tCrawl->children[idx] = new TrieNode();
                
            tCrawl = tCrawl->children[idx];
        }
        tCrawl->isEndOfWord = 1;    //最后一个字符，isEndOfWord设为1
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {  // 搜索的时候，树可能没有任何节点，只有 26个 指针都为NULL 的头节点，且 头结点 isEndOfWord 为0
        TrieNode *tCrawl = tNodeHead;
        for(int i=0; i<word.length(); i++){
            int idx = word[i] - 'a';
            if(!tCrawl->children[idx])
                return false;
            tCrawl = tCrawl->children[idx];
        }
        return tCrawl && tCrawl->isEndOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *tCrawl = tNodeHead;
        for(int i=0; i<word.length(); i++){
            int idx = word[i] - 'a';
            if(!tCrawl->children[idx])
                return false;
            tCrawl = tCrawl->children[idx];
        }
        return (tCrawl != NULL) && 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */