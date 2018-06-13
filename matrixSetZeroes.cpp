#include <iostream>
#include <vector>
//#include <climits>  恰好测试用例里出现了 INT_MAX，所以最终没用到这个库，本来是用 INT_MAX 作为 UNIQUE 值的
using namespace std;


void matrixSetZeroes(vector< vector<int> >& matrix){
	int UNIQUE = 1111111111;	// 需要设定一个 “独一无二” 的整数，不能超过int代表的最大值
                                // 确保这个数不会在测试用例的矩阵里出现，作为标记 --> 原始矩阵中每行的0元素
	int m = matrix.size(), n = matrix[0].size();	// 获取到矩阵的行数、列数

	int i,j;
	bool flag;

	for(i=0;i<m;i++){
		flag = false;	// 默认每行没有0元素

		for(j=0;j<n;j++){
			if(flag == false && matrix[i][j] == 0){	// 如果flag为false并且，如果某行有元素为0
				matrix[i][j] = UNIQUE;	// 把这行第一个0元素置为 UNIQUE，
							// 可笑的是把 = 写成了 == ，导致martrix[0][0]始终为0，结果一直不对
				flag = true;

				for(int k=j-1;k>=0;k--)	// 把这行第一个0元素之前的值都置为0，(被置0的这些元素之前都非0)
					matrix[i][k] = 0;
				j++;	// 增加1的原因是：if 里的j 对应的matrix[i][j]已经处理过
			}
			if(flag == true && j<n){	// 把这行第一个0元素之后的：非0元素全置为0，0元素全置为 UNIQUE
				if(matrix[i][j] == 0)
					matrix[i][j] = UNIQUE;
				else
					matrix[i][j] = 0;
			}
		}
	
		//if(i == 0)
		//	for(int col=0;col<n;col++)
		//		cout<<matrix[i][col]<<" ";
		//cout<<endl;
	}

	//cout << "第一次遍历后 matrix[0][0]" << matrix[0][0] <<endl;
	//cout << "第一次遍历后 matrix[0][3]" << matrix[0][3] <<endl;

	for(j=0;j<n;j++){
		flag = false;	// 默认每列没有UNIQUE元素

		for(i=0;i<m;i++){
			if(flag == false && matrix[i][j] == UNIQUE){ // 如果flag为false并且，如果某列有元素为UNIQUE
				matrix[i][j] = 0;	// 把这列第一个UNIQUE元素置为0
				flag = true;

				for(int k=i-1;k>=0;k--)
					matrix[k][j] = 0;	// 把这列第一个UNIQUE元素之前的值都置为0，(被置0的这些元素之前都非UNIQUE)
				i++;	// 增加1的原因是：if 里的i 对应的matrix[i][j]已经处理过
			}
			if (flag == true && i<m)
			{
				matrix[i][j] = 0;// 把这列第一个UNIQUE元素之后的值都置为0
			}
		}
	}

	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			cout<<matrix[i][j]<<" ";
			if(j == n-1)
				cout<<endl;
		}
}

int main(){
	int m,n;
	cin>>m>>n;
	vector< vector<int> > matrix(m, vector<int>(n));

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>matrix[i][j];

	matrixSetZeroes(matrix);
}
