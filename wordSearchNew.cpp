#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
    problem: 单词搜索
    给定一个二维网格和一个单词，找出该单词是否存在于网格中。

    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

    示例:

    board =
    [
        ['A','B','C','E'],
        ['S','F','C','S'],
        ['A','D','E','E']
    ]

    给定 word = "ABCCED", 返回 true.
    给定 word = "SEE", 返回 true.
    给定 word = "ABCB", 返回 false.

    idea:
    一般不用遍历所有情况的方法，一是容易漏掉情况，而是时间复杂度太高
    这个题和 numIslands.cpp 的解法相似，递归可以有效避免漏掉情况

    我对leetcode这个题的测试用例有异议，leetcode给出的这组测试用例：
        输入：
        [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
        "ABCESEEEFS"
        输出：
        false
        预期：
        true
    我的理由：
    （1）ABCESEEEFS 出现了4个‘E’，根据题目要求，同一单元格内字母不允许重复使用，而board里只有3个‘E’
    （2）相邻单元格是那些水平相邻或垂直相邻的单元格，按照此原则也找不到 ABCESEEEFS
*/
class Solution {
public:
    bool exist(vector< vector<char> >& board, string word) {
        cout << board.size() << ' ' << board[0].size() << endl;        
        if (board.size() > 0) {
            cout << "进入if" << endl;
            int **visited = new int * [board.size()];   // 与board行数、列数均相同的二维数组，
                                                        // 记录一次搜索中哪些元素访问过，哪些没访问过
                                                        // 因为对于一个单词word，不能重复比较board[i][j]与word中已经访问过的字符
            for(int l=0; l<board.size(); l++)
                visited[l] = new int [board[0].size()];

            for(int m = 0; m<board.size(); m++){
                for(int n = 0; n<board[0].size(); n++){
                    if(visited[m][n] != 0)
                        visited[m][n] = 0;
                }
            }

            for(int i = 0; i<board.size(); i++){
                for(int j = 0; j<board[0].size(); j++){ // 这么低级的错误，i、j没有赋初值
                    if(searchWord(board, i, j, word, 0, visited))
                        return true;
                }
            }

            delete []visited;

            return false;
        }
        return false;
    }

    bool searchWord(vector< vector<char> >& board, int i, int j, string word, int k, int **visited){   // 最后一个参数表示，word中的第k个位置
                                                                                        // 要比较word[k]和board[i][j]上下左右的四个字符是否相等
        //visited[i][j] = 1;  // 传入的board[i][j]不能代表已经访问过，要递归地访问它上下左右的邻居
        cout << "扫面到了第" << k << "个单词" << endl;

        bool flag_existed = false;
        if(k == word.length()){  // 如果满足此条件，说明 word 从第0个到第 len(word)-1 个全部匹配上，即找到该单词
            flag_existed = true;
            return flag_existed;
        }

        if(isSafe(board, i, j, visited)){
            if(board[i][j] == word[k]){
                visited[i][j] = 1;  // 二者相等才能代表board[R][C]已经访问过，要递归地访问它上下左右的邻居
                cout << "recursion char: " << word[k] << endl;
                k++;

                flag_existed = (
                    searchWord(board, i-1, j, word, k, visited) ||
                    searchWord(board, i+1, j, word, k, visited) ||
                    searchWord(board, i, j-1, word, k, visited) ||
                    searchWord(board, i, j+1, word, k, visited)
                );

                if(!flag_existed){  //如果board【R】【C】上下左右都没找到，回溯
                    k--;
                    visited[i][j] = 0;
                }
            }
        }
        return flag_existed;
    }

    bool isSafe(vector< vector<char> >& board, int R, int C, int **visited){
        if(R < board.size() && R >=0 && C < board[0].size() && C >= 0 && visited[R][C] == 0)    // 要先判断R/C是否合法，否则 visited[R][C] 可能下标溢出
            return true;
        else
            return false;
    }
};

int main(){
    vector< vector<char> > board;
    vector<char> row;
    char ch;

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin>>ch;
            row.push_back(ch);
        }
        board.push_back(row);
        row.clear();
    }

    string word;
    cout<<"input a word: ";
    cin>>word;

    Solution *solu = new Solution();
    cout << "existed? " << solu->exist(board, word) << endl;
}
