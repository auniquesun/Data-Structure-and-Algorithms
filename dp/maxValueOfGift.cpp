#include<algorithm>	// max函数

/*
problem: 给定一个 gift board，相当于一个二维数组，数组元素值为非负整数；
			从数组左上角开始，每次只能向右或向下移动一步，直到移动到最后一行/最后一列
			求移动过程中，经过的元素和最大的那个值，相当礼物最多

idea：
	一. 肯定是动态规划了，开辟一个二维数组max_value，max_value[i][j]
		表示从左上角到达 位置（i，j）经过元素和最大的值
		最后返回 max_value[row-1][col-1] 即可

	二. 容易知道，gift[i][j] 是从gift[i-1][j]或者gift[i][j-1]到达的，
		所以 max_value 第i-2行及之前的行并不需要存储，
		方案一中存在着空间浪费的情况，如何减少空间的使用呢？
		仅开辟一个 大小为 col 的一维数组max_value，前j个元素记录
		到gift[i][j]左边元素路径和的最大值，后n-j个元素记录到gift[i][j]上边
		元素路径和的最大值
		最后返回 max_value[col-1]
*/

int maxValueOfGift(vector< vector<int> > gift){
	if(gift.size() > 0 && gift[0].size() > 0){
		int row = gift.size();
		int col = gift.size();

		int *max_value = new int [col];

		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				int up = 0, left = 0;

				if(i>0)	up = max_value[j];
				if(j>0) left = max_value[j-1];

				max_value[j] = max(up, left) + gift[i][j]; 
			}
		}

		int maxValueOfGift = max_value[col-1];
		delete [] max_value;
		return maxValueOfGift;
	}
	else{
		cout << "gift is NULL" << endl;
		return 0;
	}
}