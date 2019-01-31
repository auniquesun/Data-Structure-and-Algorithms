#include<iostream>
#include <vector>
using namespace std;

/*
problem: 求 第 K个丑数
			什么是丑数呢？ 
			把一个数字作因式分解，因式中只包含1/2/3/5中的一项或多项
			例： 1是丑数，10是丑数，20是丑数；14不是丑数，33不是丑数

idea： a. 简单的方法，从1开始数字每次累加，同时设置一个丑数计数器，
		判断每个数字是不是丑数，直到计数器达到K	

		b. 高级的方法，每次按顺序产生一个丑数，直到第K个结束
            跟踪三个索引：M2，M3，M5
*/

int min(int a, int b, int c){
	int minOf2 = a<b?a:b;
	return minOf2<c?minOf2:c;
}

int getKthUglyNumber(int K){
	if(K<=0)
		return 0;
	int *uglyNumbers = new int [K];
	uglyNumbers[0] = 1;
	int count = 1;	//统计丑数个数

	int *uglyNumber2 = uglyNumbers;
	int *uglyNumber3 = uglyNumbers;
	int *uglyNumber5 = uglyNumbers;

	while(count < K){
		int min_value = min(2*(*uglyNumber2), 3*(*uglyNumber3), 5*(*uglyNumber5));
		uglyNumbers[count++] = min_value;

		if(2*(*uglyNumber2) <= min_value)
			uglyNumber2++;
		if(3*(*uglyNumber3) <= min_value)
			uglyNumber3++;
		if(5*(*uglyNumber5) <= min_value)
			uglyNumber5++;
	}

	int KthUglyNumber = uglyNumbers[K-1];
	delete [] uglyNumbers;
	return KthUglyNumber;
}

int main(int argc, char const *argv[])
{
	/* code */
	int K;
	cout << "K: "; cin >> K;
	cout << "Kth ugly number is: " << getKthUglyNumber(K) << endl;
	return 0;
}
