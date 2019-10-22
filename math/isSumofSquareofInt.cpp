#include<iostream>
#include<stack>
#include<cmath>

/*
problem: 给定一个整数n，输出n的一个划分，要求：
            划分次数最少，
            划分中每个数是某个整数的平方，
            划分的所有数加和等于n
        若没有满足要求的划分，输出-1
idea:   这个题其实用二重循环扫面就行，
        循环过程中设一个栈，看加和是否满足要求，出栈入栈
*/

using namespace std;

int main(){
    int n;
    cin >> n;

    int sqrt_n = int(sqrt(n));
    if(sqrt_n*sqrt_n == n){
        cout << n << endl;
    }
    else{
        stack<int> st;
        bool flag = true;
        for(int i=sqrt_n; flag&&i>=1; i--){
            int sum = 0;
            for(int j=i; j>=1; j--){
                sum += j*j;
                if(sum < n){
                    st.push(j);
                }
                else if(sum == n){
                    st.push(j);
                    flag = !flag;
                    break;
                }
                else{
                    // 因为这种情况没有入栈j，所以不用出栈，只要把j*j减掉就行了
                    sum -= j*j;
                }
            }
        }

        if(flag)
            cout << -1;
        else{
            while(!st.empty()){
                int top = st.top();
                st.pop();
                cout << top*top << " ";
            }
        }                
        cout << endl;
    }
}