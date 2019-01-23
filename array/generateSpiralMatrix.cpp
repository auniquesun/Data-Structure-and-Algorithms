class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector< vector<int> > res;
        if(n == 0)
            return res;
        if(n == 1){
            vector<int> val;
            val.push_back(1);
            res.push_back(val);
            return res;
        }
        //注意二维数组的建立方法
        int **arr = new int * [n];

        for(int i=0;i<n;i++){
            arr[i] = new int [n];
        }

        int val = 1;    //arr数组第一个元素的值
        int start_row=0, start_col=0;
        int end_row=n, end_col=n;

        while(start_row < end_row && start_col < end_col){
            //数组arr，未填充部分，第一行
            for(int i=start_col;i<end_col;i++){
                arr[start_row][i] = val;
                val++;
            }
            start_row++;

            //数组arr，未填充部分，最后一列
            for(int i=start_row;i<end_row;i++){
                arr[i][end_col - 1] = val;
                val++;
            }
            end_col--;

            if(start_row < end_row){
                //数组arr，未填充部分，最后一行，从后向前
                for(int i=end_col-1;i>=start_col;i--){
                    arr[end_row-1][i] = val;
                    val++;
                }
                end_row--;
            }
            
            if(start_col < end_col){
                //数组arr，未填充部分，第一列，从后向前
                for(int i=end_row-1;i>=start_row;i--){
                    arr[i][start_col] = val;
                    val++;
                }
                start_col++;
            }
        }

        for(int i=0;i<n;i++){
            vector<int> row;
            for(int j=0;j<n;j++){
                row.push_back(arr[i][j]);
            }
            res.push_back(row);
            row.clear();
        }

        return res;
    }
};