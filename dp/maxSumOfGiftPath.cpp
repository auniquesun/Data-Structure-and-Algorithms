#include<vector>
#include<iostream>

using namespace std;

int maxSumOfGiftPath(vector<int> gifts, int rows, int cols){
    int maxSum = 0;
    cout << "gifts.size: " << gifts.size() << endl;
    cout << "rows:" << rows << endl;
    cout << "cols:" << cols << endl;
    if(gifts.size() > 0 && gifts.size() == rows * cols){
        cout << "进来了吧" << endl;
        int **maxValues = new int *[rows];
        for(int i=0; i<rows; i++)
            maxValues[i] = new int[cols];

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                // 正确的解法
                if(i == 0 && j==0)
                    maxValues[i][j] = gifts[0];
                else if(i == 0)
                    maxValues[i][j] = maxValues[i][j-1] + gifts[i*cols + j];
                else if(j == 0)
                    maxValues[i][j] = maxValues[i-1][j] + gifts[i*cols + j];
                else
                    maxValues[i][j] = max(maxValues[i-1][j], maxValues[i][j-1]) + gifts[i*cols + j];
            }
        }

        maxSum = maxValues[rows-1][cols-1];
        cout << "maxValues" << endl;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++)
                cout << maxValues[i][j] << " ";
            cout << endl;
        }
        for(int i=0; i<rows; i++)
            delete[] maxValues[i];
        delete[] maxValues;        
    }
    return maxSum;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> gifts;
    int val;
    for(int i=0; i<16; i++){
        cin >> val;
        gifts.push_back(val);
    }

    cout << "maxSumOfGiftPath: " << maxSumOfGiftPath(gifts, 4, 4) << endl;
    return 0;
}
