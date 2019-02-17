#include<iostream>
using namespace std;
/*
 * problem: 不用加减乘除法，求两个数的和
 *
 * idea：不能用加减乘除，还要做加法，
 *          根据计算机组成原理的知识，应该用位运算了
 *          a. 两个数先做按位异或
 *          b. 再做按位与，按位与得到的结果表明哪些位有进位
 *              所以将按位与的结果左移一位
 *          c. 将a，b步骤的结果相加, 直到进位为0
 */
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
