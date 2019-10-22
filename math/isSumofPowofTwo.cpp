/*
problem: 给定一个正整数n，把n分解为若干个正整数的和，要求分解出来的正整数个数最少，
            并且每个正整数是2的幂次方
            例：n=65, 输出1,64；n=51，输出1,2,16,32
idea: 这道题看上去挺咋胡的，其实就是把n转换为二进制数，找到对应位置的1，转换成对应的十进制            
*/
#include<iostream>
#include<stack>
#include<cmath>

using namespace std;

int main(){
    int n;
    cout << "n: ";
    cin >> n;

    stack<int> st;
    int tmp = n;
    int count = 0;
    do{
        st.push(tmp%2);
        tmp /= 2;
        count++;
    }while(tmp);

    while(count > 0){
        int top = st.top();
        st.pop();
        if(top){
            cout << pow(2, count-1) << " ";
        }
        count--;
    }
    cout << endl;
}