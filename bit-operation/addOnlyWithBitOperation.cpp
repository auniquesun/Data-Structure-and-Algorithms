#include<iostream>
using namespace std;

int addOnlyWithBitOperation(int a, int b){
    int sum, carry;
    do{
        cout << "a: " << a << ", b: " << b << endl;
        sum = a^b;
        carry = (a&b) << 1;
        a = sum;
        b = carry;
    }while(b!=0);

    return a;
}

int main(){
    int A, B;
    cout << "input A, B respectively: ", cin >> A >> B;
    cout << "sum of A and B: " << addOnlyWithBitOperation(A, B) << endl;
}
