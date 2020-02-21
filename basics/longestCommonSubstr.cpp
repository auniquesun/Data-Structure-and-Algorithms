#include "public.h"

class Solution{
    public:
    void longestCommonSubstr(string X, string Y){
        int m = X.size();
        int n = Y.size();

        // 需要显式初始化为0
        int LCS[m+1][n+1] = {0};
        // 记录最长公共子序列长度
        int max_len = 0;
        int row, col;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0)
                    LCS[i][j] == 0;
                else if(X[i] == Y[j]){
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                    if(max_len < LCS[i][j]){
                        max_len = LCS[i][j];
                        row = i;
                        col = j;
                    }
                }
                else{
                    LCS[i][j] = 0;
                }
            }
        }

        cout << "[到这儿还是没问题的]" << endl;
        char res[max_len+1];
        res[max_len] = '\0';

        for(int i=max_len-1; LCS[row][col]!=0; --i){
            res[i] = X[row];
            --row;
            --col;
        }

        for(int i=0; i<=max_len; i++)
            cout << res[i];
    }
};

int main(){
    Solution *solu = new Solution();
    solu->longestCommonSubstr("OldSite:GeeksforGeeks.org", "NewSite:GeeksQuiz.com");
}
