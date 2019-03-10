#include <iostream>
using namespace std;

/*
 *  problem: 给定一个 base，一个exponent，求 pow(base, exponent)
 *              其中 base 为double型，exponent为无符号整数 
 *
 *  idea:   为什么想到用位运算做呢，unsigned int exponet 可能给我们些启发，为什么呢？
 *              为什么 exponent 是unsigned int型，因为这样移位的时候不用考虑正负号，
 *              如果是int型，exponent为负数的话，负数最高位是1，影响移位操作
 */
double powerWithUnsignedExponent(double base, unsigned int exponent){
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;
    double result = powerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if(exponent & 1)    //判断奇偶数的新思路
        result *= base;
    return result;
}

int main(){
    double base = 3.;
    int exponent = 8;
    cout << "pow(" << base << "," << exponent << ") = " << powerWithUnsignedExponent(base, exponent) << endl;
}
