#include<iostream>
#include <vector>
#include <climits>

using namespace std;


/*
	problem：
	一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

	机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

	问总共有多少条不同的路径？



	例如，上图是一个7 x 3 的网格。有多少可能的路径？

	说明：m 和 n 的值均不超过 100。

	示例 1:

	输入: m = 3, n = 2
	输出: 3
	解释:
	从左上角开始，总共有 3 条路径可以到达右下角。
	1. 向右 -> 向右 -> 向下
	2. 向右 -> 向下 -> 向右
	3. 向下 -> 向右 -> 向右

	idea：
	（1）从左上角到右下角，要计算有几条不同的可达路径；
		路径肯定是连续的，只要计算出前面的点有多少条可达路径，
		再逐步累加，计算出可达后面的点的路径数

	（2）用递归的方法也能解决这个问题，不过随着递归次数增加，
		时空复杂度都迅速增加，计算效率并不高
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
    	if(m>0 && n>0){
	        int count[m][n];	// 用来记录走到每个点的路径数

	        for(int i=0;i<m;i++)	// 因为只能向下走，所以第一列的只有一条路径可达，count值全为1
	        	count[i][0] = 1;

	        for(int j=0;j<n;j++)	// 同理
	        	count[0][j] = 1;
    		
    		for(int i=1;i<m;i++)
    			for(int j=1;j<n;j++)
    				count[i][j] = count[i-1][j] + count[i][j-1];	// count[i][j]经由count[i-1][j]，count[i][j-1]到达
    																// 所以它的取值为二者之和

    		return count[m-1][n-1];
    	}

    	return 0;

    	/*	递归的方法，代码很简单，计算效率不高
		if (m == 1 || n == 1)
        	return 1;
 	   
	    return  uniquePaths(m-1, n) + uniquePaths(m, n-1);
    	*/
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	int num_row, num_col;
	cout << "input num_row, num_col: "
	cin >> num_row >> num_col;

	Solution *solu = new Solution();
    int num = solu->uniquePaths(nums);

    cout << "number of unique Paths: " << num << endl;
	return 0;
}