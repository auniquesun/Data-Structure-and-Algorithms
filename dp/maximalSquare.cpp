/*
problem:
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

idea:
这种矩阵的题，先往动态规划的地方想，我是想到动态规划了，细节没想完整：
    1. 定义怎样的数据结构，这个数据结构表示怎么样的含义
    2. 如何初始化这个数据结构
    3. 如何迭代求解数据结构中的值
*/

class Solution {
public:
    int minValue(int a, int b, int c){
        return (a<b)?(a<c?a:c):(b<c?b:c);
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_len = 0;    // 记录面积最大正方形的边长；当然可以直接记录面积
        if(matrix.size()>0 && matrix[0].size()>0){
            int m = matrix.size();
            int n = matrix[0].size();
            int len[m][n];  // len[i][j] 表示以 (i,j) 为右下角的正方形，最大的边长

            // 下面两个循环，都是初始化
            for(int i=0; i<m; i++){ // 作为第一列的正方形，边长最大只能为1
                len[i][0] = matrix[i][0] - '0';
                max_len = max(max_len, len[i][0]);
            }

            for(int j=0; j<n; j++){ // 作为第一行的正方形，边长最大只能为1
                len[0][j] = matrix[0][j] - '0';
                max_len = max(max_len, len[0][j]);
            }

            // 迭代
            for(int i=1; i<m; i++){
                for(int j=1; j<n; j++){
                    len[i][j] = (matrix[i][j] == '1')?(minValue(len[i-1][j-1], len[i-1][j], len[i][j-1]) + 1):0;
                    max_len = max(max_len, len[i][j]);
                }
            }
        }

        return max_len*max_len;
    }
};
