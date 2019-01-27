#include<iostream>
#include <vector>
using namespace std;

/*
problem： N皇后问题，给定一个NxN方格，任意两个皇后不能
			位于同一行，同一列，同一对角线
*/
bool isSafe(vector< vector<int> > board, int row, int col){
	if(board.size() > 0 && board[0].size() > 0){
		// 所在的列没有值为1的
		for(int i=0; i<=row; i++)
			if(board[i][col] == 1)
				return false;
		// 不用检查 "所在的行没有值为1的"，因为是一行一行放的

		// 检查对角线，左上
		for(int i=0, j=0; i<=row && j<=col; i++, j++)
			if(board[i][j] == 1)
				return false;
		// 检查对角线，右上
		for (int i=row, j=row; i>=0 && j<board[0].size(); i--, j++)
			if(board[i][j] == 1)
				return false;

		return true;
	}

	return false;
}

bool solveNQueenUtil(vector< vector<int> > &board, int row){
	if(row == board.size())
		return true;
	if(board.size() > 0 && board[0].size() > 0){
		for(int j=0; j<board[0].size(); j++){
			if(isSafe(board, row, j)){
				board[row][j] = 1;
				if(solveNQueenUtil(board, row+1))	//如果本行满足，前往下一行，递归的特性
					return true;
				// 回溯就体现在这呢
				board[row][j] = 0;
			}
		}
		return false;
	}
	else
		return false;
}

void solveNQueen(){
	int N;
	cout << "N: ";
	cin >> N;

	int val=0;
	vector<int> row;
	vector< vector<int> > board;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			row.push_back(val);
		board.push_back(row);
		row.clear();
	}

	solveNQueenUtil(board, 0);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			cout << board[i][j]	<< " ";
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	solveNQueen();
	return 0;
}
