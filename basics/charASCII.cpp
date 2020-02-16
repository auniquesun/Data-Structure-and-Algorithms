#include<iostream>

using namespace std;

/*
    字符'a'的 ASCII 码是97
    字符'A'的 ASCII 码是65

    output: 98
*/

int fun(int a, char c){
    return a+c;
}

int main(){

    int a = 1;
    char c = 'a';
    cout << fun(a,c) << endl;
    cout << int('A') << endl;
}
