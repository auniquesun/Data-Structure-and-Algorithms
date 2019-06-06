/*
problem:
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

idea:
这个题比较精妙吧，因为输入矩阵的性质，
用右上角元素和 target 比，相同直接返回 true；不同时决定前进一行还是一列，O(n) 的时间复杂度，n代表行数或列数
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()>0 && matrix[0].size()>0){
            for(int i=0, j=matrix[0].size()-1; i<matrix.size() && j>-1; ){  // 初始化，第一行，最后一列
                if(matrix[i][j] == target)
                    return true;
                else if(matrix[i][j] > target)  // target小于右上角，向前一列移动
                    j--;
                else
                    i++;
            }
            return false;
        }
        return false;
    }
};