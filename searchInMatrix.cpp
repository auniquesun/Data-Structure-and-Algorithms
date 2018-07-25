#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	problem:
	编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

	每行的元素从左到右升序排列。
	每列的元素从上到下升序排列。
	示例:

	现有矩阵 matrix 如下：

	[
  	[1,   4,  7, 11, 15],
  	[2,   5,  8, 12, 19],
  	[3,   6,  9, 16, 22],
  	[10, 13, 14, 17, 24],
  	[18, 21, 23, 26, 30]
	]
	给定 target = 5，返回 true。

	给定 target = 20，返回 false。

	idea:
	（1）先比较 num_row 和 num_col 的大小，把其中小的数作为外层循环条件，大的数作为内层循环条件
	（2）对内层循环运用 "二分查找"，如果找到则返回；如果没找到，确定在哪一列，进入（3）
	（3）再列内继续运用"二分查找"
*/


class Solution {
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
		if(matrix.size() > 0 && matrix[0].size() > 0){
			int num_row = matrix.size();
			int num_col = matrix[0].size();
			
			int sign = -1;	// 用来标记是 搜索行（-1）还是搜索列（1）
			// 默认行为外层循环
			int num_outer_loop = num_row;
			int num_inner_loop = num_col;

			if(num_row > num_col){	
				sign = 1;	// 标记列为外层循环
				num_outer_loop = num_col;
				num_inner_loop = num_row;
			}

			// （1）首先从"当前行"搜寻 target，如果找到返回true
			// （2）如果"当前行"没有，再定位到"当前行与target最接近的那个值"对应的那一列，继续从列中搜索，找到返回true，否则进入（3）
			// （3）重复（1）（2），退出循环后，返回false
			for (int i = 0; i < num_outer_loop; ++i)	// 循环里的 rowId，colId 只是抽象意义的行号、列号，并不与实际的matrix行号、列号对应，有可能是rowId对应实际的列号，colId对应实际的行号
				// 同理，left，right也是抽象意义的左、右；down，up也是抽象意义的下、上，它们用来表示调用 binary_search 时上下界的参数
			{
				/* code */				
				int index = -1;

				int rowId = i;
				int left = 0, right = num_inner_loop - 1;	// 注意这里 右边界是 num_inner_loop - 1，而不是 num_inner_loop
				

				bool flag = binary_search(matrix, rowId, left, right, target, sign, index);	// index是引用传递
																							// index的作用是：在行中没有搜索到 target时，确定从哪一列搜索，记录列号
				if(flag == true)
					return flag;
				else{
					int colId = index;	// rowId 没这一行没找到，定位到 index 这一列继续寻找
					int down = 0, up = num_outer_loop - 1;
					sign = -sign;

					bool tag = binary_search(matrix, colId, down, up, target, sign, index);
					if(tag == true)
						return tag;

					sign = -sign;	// 如果 tag == false，再次改变sign的符号，为重新进入循环作准备
				}
			}
			return false;
		}	
		else{
			return false;
		}	        	
    }

    bool binary_search(vector< vector<int> >& matrix, int Id, int lower_bound, int upper_bound, int target, int sign, int& index){
    	while(lower_bound <= upper_bound){
    		index = upper_bound;

    		int mid = (lower_bound + upper_bound) / 2;
    		int value;

    		if(sign == -1)	// 判断是对 行元素赋值 还是 列元素赋值
    			value = matrix[Id][mid];
    		else
    			value = matrix[mid][Id];

    		if(value == target){
    			return true;
    		}
    		else if(value > target){
    			upper_bound = mid - 1;
    		}
    		else{
    			lower_bound = mid + 1;
    		}
    	}
    	return false;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	cout<<"input matrix: "<<endl;

	vector< vector<int> > matrix;
	vector<int> row;
	int item;
	for (int i = 0; i < 5; ++i)
	{
		/* code */
		for (int j = 0; j < 5; ++j)
		{
			/* code */
			cin>>item;
			row.push_back(item);
		}
		matrix.push_back(row);
	}

	int target;
	cout<<"input target: "<<endl;
	cin>>target;

	Solution *solu = new Solution();
	bool exist =  solu->searchMatrix(matrix);

	cout<<"is target in this matrix? ->"<<exist<<endl;

	return 0;
}