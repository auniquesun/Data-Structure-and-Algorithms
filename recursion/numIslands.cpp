#include<iostream>
#include <vector>

using namespace std;

// =================== problem =================
// 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

// 示例 1:

// 输入:
// 11110
// 11010
// 11000
// 00000

// 输出: 1
// 示例 2:

// 输入:
// 11000
// 11000
// 00100
// 00011

// 输出: 3

// ==================== idea ===================
// 要求一幅图中岛屿的个数，这个问题相当于：
// 	对于图中的一块陆地，要把与它相邻的陆地连接起来，"拼接"成一个岛屿，
// 	最终岛屿的个数，就是"拼接"的次数

// 	用什么方法能把一块陆地相邻的陆地都访问到呢？	常用的方法就是：深度优先搜索/广度优先搜索
// 	我采用的解法是深度优先搜索

class Solution {
public:
    int numIslands(vector< vector<char> >& grid) {
        int num_islands = 0;

        if(grid.size() > 0){        	
	        int row = grid.size();
	        int col = grid[0].size();

	        int i,j;
	        int **visited = new int* [row];		// 二维数组，0代表对应的grid[i][j]没有访问过
	        for(i=0;i<row;i++)
	        	visited[i] = new int [col];		// 初值默认为0，经过测试

	        for(i=0;i<row;i++)
	        	for(j=0;j<col;j++)
	        		visited[i][j] = 0;

	        for(i=0;i<row;i++)
	        	for(j=0;j<col;j++){	// 每调用一次 dfsGraph，就相当于"拼接"成了一个岛屿
	        		if(grid[i][j] == '1' && visited[i][j] == 0){ 	// 遇到一个‘陆地’，并且没有访问过，
	        													// 调用深度优先搜索，把它周围所有的陆地都访问
	        			dfsGraph(grid, visited, i, j);
	        			num_islands++;
	        		}
	        	}

        }

        return num_islands;
    }

    void dfsGraph(vector< vector<char> >& grid, int **visited, int i, int j){
    	int x_neighbor[] = {0,0,-1,+1};	// 以grid（i，j）为中心，它上下左右的四个grid坐标
    	int y_neighbor[] = {-1,1,0,0};

    	visited[i][j] = 1;

    	for(int k=0;k<4;k++)
    		if(isSafe(grid,visited,i+x_neighbor[k],j+y_neighbor[k]))	// 要判断访问的节点是否存在于gird，是否是一块陆地，是否被访问过
    			dfsGraph(grid,visited,i+x_neighbor[k],j+y_neighbor[k]);
    }

    int isSafe(vector< vector<char> >& grid, int **visited, int i, int j)
	{
	    // i is in range, j is in range and value is 1 
	    // and not yet visited
	    return (i >= 0) && (i < grid.size()) &&     
	           (j >= 0) && (j < grid[0].size()) &&      
	           (grid[i][j] == '1' && !visited[i][j]); 
	}
};

int main(){
	int num_row, num_col;
	cin >> num_row >> num_col;

	vector< vector<char> > grid;	// 存放一幅图，这幅图由 0（水域）和 1（陆地）组成
	vector<char> v;	// 存放gird每行的值

	for(int i=0;i<num_row;i++){
		for (int j = 0; j < num_col; j++)
		{
			/* code */
			int item;
			cin>>item;
			if(item == 0)
				v.push_back('0');
			else
				v.push_back('1');
		}
		grid.push_back(v);
		v.clear();		
	}

	Solution *solu = new Solution();
	int nums = solu->numIslands(grid);
	
	cout << "numIslands: " << nums << endl;

	return 0;
}
