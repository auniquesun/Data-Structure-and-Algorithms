/*
problem：螺旋矩阵
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

idea：
顺时针螺旋遍历，按照这个顺序，控制好索引下标就好
每次取出 "剩余" 矩阵中的 --
	开始行
	末尾列
	末尾行
	开始列
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

    	if(matrix.size() == 0)
    		return res;

        /*  start_row - starting row index 
            end_row - ending row index 
            start_col - starting column index 
            end_col - ending column index 
            i - iterator 
        */
        int i, start_row = 0, start_col = 0;
        int end_row = matrix.size(), end_col = matrix[0].size(); 
  
        while (start_row < end_row && start_col < end_col) 
        { 
            /* Print the first row from the remaining rows */
            for (i = start_col; i < end_col; ++i) 
            { 
                res.push_back(matrix[start_row][i]); 
            } 
            start_row++;	//及时改变所有操作，下同
    
            /* Print the last column from the remaining columns */
            for (i = start_row; i < end_row; ++i) 
            { 
                res.push_back(matrix[i][end_col-1]); 
            } 
            end_col--; 
    
            /* Print the last row from the remaining rows */
            if ( start_row < end_row) 	//此时要求 开始行 < 结束行
            { 
                for (i = end_col-1; i >= start_col; --i) 
                { 
                    res.push_back(matrix[end_row-1][i]); 
                } 
                end_row--; 
            } 
    
            /* Print the first column from the remaining columns */
            if (start_col < end_col) 	// 此时要求 开始列 < 结束列
            { 
                for (i = end_row-1; i >= start_row; --i) 
                { 
                    res.push_back(matrix[i][start_col]); 
                } 
                start_col++;     
            }         
        }

        return res;
    }
};