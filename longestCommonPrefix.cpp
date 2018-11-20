#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    //递归判断前后字符串第k个位置上的两个字符是否相等
    void isSame(vector<string>& strs, int i, int k, int &sum){
        if(strs.size() == 0){   //空向量，strs
            sum = -1;
        }
        else if(strs.size() == 1){
            sum = -2;
        }
        else if(i+1<strs.size()){    //防止下标溢出
            if(strs[i][k] == strs[i+1][k]){
                sum += 1;
                isSame(strs, i+1, k, sum);
            }
            else return;
        }
        else{
            return;   //表明strs[0][k]...strs[n-1][k]全部相等
        }
    }
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        int i=0, k=0, sum=0;
        while(1){
            isSame(strs, i, k, sum);
            if(sum == -1)   // 空向量
                break;
            else if(sum == -2){ //仅包含一个字符串
                k = strs[0].length();
                break;
            }
            else if(sum == strs.size()-1){  //找到一个公共的字符，继续找下去
                sum = 0;
                k++;
            }
            else break; //公共字符全部找完
        }

        if(strs.size()>0) 
            for(int j=0;j<k;j++)
                prefix += strs[0][j];

        return prefix;
    }
};

int main(){
    vector<string> strs;
    string str;

    cout << "strs.size: " << strs.size() << endl;
    int i=0;
    while(i<3){
        cin>>str;
        strs.push_back(str);
        i++;
    }

    Solution *solu = new Solution();
    string prefix = solu->longestCommonPrefix(strs);
    cout << "longest common prefix: " << prefix << endl;
}