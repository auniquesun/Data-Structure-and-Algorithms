#include <iostream>
#include <vector>
using namespace std;

/*
problem:
	给定一个有序数组sortedArray，给定一个数值K，返回K在有序数组中出现的次数
idea:
	1. 从头到尾扫描一次，统计出K出现的次数，时间复杂度为O(n)
	2. 方法1 没有利用数组有序的特性，凡是有序数组的题，应该想一想二分查找
		a. 找出K在数组中的第一个位置first和最后一个位置last
		b. first，last中间的位置一定都是K
		c. 返回 last - first + 1
*/

int getFirstIndexOfK(vector<int> sortedArray, int K){
	if(left > right){
		cout << "left > right" << endl;
		return -1;
	}
    int left = 0, right = sortedArray.size() - 1;
	while(left < right){
		int index = (left + right) / 2;
		if(sortedArray[index] == K){
			if((index > 0 && sortedArray[index-1] != K) || index == 0)
				return index;
			else
				right = index - 1;
		}
		else if(sortedArray[index] < K)
			left = index + 1;
		else
			right = index - 1;
	}
}

int getLastIndexOfK(vector<int> sortedArray, int K){
	if(left > right){
		cout << "left > right" << endl;
		return -1;
	}
    int left = 0, right = sortedArray.size() - 1;
	while(left < right){
		int index = (left + right) / 2;
		if(sortedArray[index] == K){
			if((index < sortedArray.size() - 1 && sortedArray[index+1] != K) || index == sortedArray.size() - 1)
				return index;
			else
				left = index + 1;
		}
		else if(sortedArray[index] < K)
			left = index + 1;
		else
			right = index - 1;
	}
}

int getNumberOfK(vector<int> sortedArray, int K){
	return getLastIndexOfK(sortedArray, K) - getFirstIndexOfK(sortedArray, K) + 1;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> sortedArray;
	int K, val;
	cout << "K: ", cin >> K;
	do{
		cin >> val;
		if(val != 1111111)
			sortedArray.push_back(val);
	}while(val != 1111111);
	cout << "Number Of K: " << getNumberOfK(sortedArray, K) << endl;
	return 0;
}
