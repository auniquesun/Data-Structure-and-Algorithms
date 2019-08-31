#include<iostream>
#include<sstream>
#include<vector>
#include<cstdlib>   // atoi(char*)

using namespace std;

/*
problem:
输入一个字符串，这个字符串由数字和逗号组成，
一个数字后面跟着一个逗号，最后一个数字后没有逗号
要求把这个字符串的数字按照顺序存放到一个整型数组，这个题目的是学会使用string stream
example:
string str = "1,2,3,4,5";
output:
int *arr = [1,2,3,4,5];
*/
int main(){
    string str;
    cin >> str;

    istringstream iss(str);
    string tmp;
    vector<int> nums;
    while(getline(iss, tmp, ',')){
        // 因为 atoi 要传入字符指针，所以用 c_str() 方法
        nums.push_back(atoi(tmp.c_str()));
    }

    for(auto num:nums)
        cout << num << endl;
}
