/*
problem: 
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

idea:
本题的关键是在不开辟新的 O(N*N) 的空间下将数组旋转
那肯定是找规律啦，对于本题
对于N*N方形矩阵，有 N/2 个正方形环，对于每个环做付下操作——
先把 左上角 的元素用变量temp存起来，然后按如下次序赋值——
    左下角 -> 左上角
    右下角 -> 左下角
    右上角 -> 右下角
    temp   -> 右上角
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int N = matrix.size();
        // Consider all squares one by one 
        for (int i = 0; i < N / 2; i++) 
        { 
            // Consider elements in group of 4 in  
            // current square 
            for (int j = i; j < N-i-1; j++) 
            { 
                // store current cell in temp variable 
                int temp = matrix[i][j]; 

                // move values from bottom left to top left
                matrix[i][j] = matrix[N-1-j][i]; 

                // move values from bottom right to bottom left
                matrix[N-1-j][i] = matrix[N-1-i][N-1-j]; 

                // move values from top right to bottom right
                matrix[N-1-i][N-1-j] = matrix[j][N-1-i]; 

                // assign temp to top right 
                matrix[j][N-1-i] = temp; 
            } 
        }
    }
};