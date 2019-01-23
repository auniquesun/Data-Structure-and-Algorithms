#include<iostream>
using namespace std;

/*
给定一个序列	arr[0,1,...,n-1]，求其最长递增子序列
用L(i) 表示 以arr[i]元素为结尾的最长递增子序列的长度
递归的思想：
L(i) = max(L(j)) + 1, 如果 j < i and arr[j] < arr[i]
L(i) = 1, 如果这样的 j 不存在
*/

//递归主体函数
int recur_LIS(int arr[], int n, int *max_ref){
	// 递归退出条件
	if(n == 1)
		return 1;

	// max_ending_here 是以arr[n-1]结尾的最长递增子序列的长度
	int res, max_ending_here = 1;

	// 递归得到以 arr[0] arr[1] arr[n-2] 元素为结尾的最长递增子序列，
	// 如果 arr[i-1] < arr[n-1]，则更新 以 arr[n-1]元素为结尾的 最长递增子序列长度
	for(int i = 1;i < n;i++){
		res = recur_LIS(arr,i,max_ref);
		if(arr[i-1] < arr[n-1] && res + 1 > max_ending_here)
			max_ending_here = res + 1;
	}

	// 比较 max_ref 与 当前 max_ending_here
	// 若当前长度大于 max_ref，则更新
	if(*max_ref < max_ending_here)
		*max_ref = max_ending_here;

	return max_ending_here;
}

//递归调用入口
int LIS(int arr[], int n){
	// 假设最大长度为 1
	int max = 1;

	// 引用传递，max会随着 recur_LIS() 的更改变化 
	recur_LIS(arr, n, &max);

	return max;
}

int main(){
	int arr[] = {7,5,8,14,23,16,50,20,35};

	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "length of lis is: " << LIS(arr,n) <<endl;
}
