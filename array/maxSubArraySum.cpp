// ==================== idea ====================
// Initialize:
//     max_so_far = 0
//     max_ending_here = 0

// Loop for each element of the array
//   (a) max_ending_here = max_ending_here + a[i]
//   (b) if(max_ending_here < 0)
//             max_ending_here = 0
//   (c) if(max_so_far < max_ending_here)
//             max_so_far = max_ending_here
// return max_so_far


// ==================== example ====================
//     {-2, -3, 4, -1, -2, 1, 5, -3}

//     max_so_far = max_ending_here = 0

//     for i=0,  a[0] =  -2
//     max_ending_here = max_ending_here + (-2)
//     Set max_ending_here = 0 because max_ending_here < 0

//     for i=1,  a[1] =  -3
//     max_ending_here = max_ending_here + (-3)
//     Set max_ending_here = 0 because max_ending_here < 0

//     for i=2,  a[2] =  4
//     max_ending_here = max_ending_here + (4)
//     max_ending_here = 4
//     max_so_far is updated to 4 because max_ending_here greater 
//     than max_so_far which was 0 till now

//     for i=3,  a[3] =  -1
//     max_ending_here = max_ending_here + (-1)
//     max_ending_here = 3

//     for i=4,  a[4] =  -2
//     max_ending_here = max_ending_here + (-2)
//     max_ending_here = 1

//     for i=5,  a[5] =  1
//     max_ending_here = max_ending_here + (1)
//     max_ending_here = 2

//     for i=6,  a[6] =  5
//     max_ending_here = max_ending_here + (5)
//     max_ending_here = 7
//     max_so_far is updated to 7 because max_ending_here is 
//     greater than max_so_far

//     for i=7,  a[7] =  -3
//     max_ending_here = max_ending_here + (-3)
//     max_ending_here = 4


#include<iostream>
#include<climits> // INT_MIN用到这个库

using namespace std;

int maxSubArraySum(int a[], int size){ // 如果 a 数组全为负数，返回0
	int max_so_far = INT_MIN, max_ending_here = 0;

	int num_zero = 0;	// 记录当前区间内0的个数
	for(int i = 0; i < size; i++){
		max_ending_here += a[i];
		if(a[i] == 0)
			num_zero++;
		// 题目要求，区间内连续0的个数不超过3
		if(max_so_far < max_ending_here && num_zero <= 3)
			max_so_far = max_ending_here;
		if(max_ending_here < 0 || num_zero > 3){
			max_ending_here = 0;
			num_zero = 0;
		}
	}

	return max_so_far;
}

int main(){
	int i,n;
	cin >> n;

	int a[n];
	for(i=0;i<n;i++)
		cin >> a[i];

	cout << "max continous array sum is: " << maxSubArraySum(a,n) << endl;
}