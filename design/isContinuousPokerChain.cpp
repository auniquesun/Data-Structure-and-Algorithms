#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
/*
problem:
	给定一幅扑克牌，从中任意抽取N张牌，判断这N张牌能否组成链子。
	如果抽到大王/小王，能代替任意数字
	例。N = 6，抽到的牌是 8,大王,10，J，Q，K，返回true（大王能替换成9）
		N = 4，抽到的牌是 2,2,3,4，返回false（存在对子，肯定不能组成链子）
idea：
	1. 先把扑克牌中的牌，对应到数学中的数字
		A-1，J-11，Q-12，K-13，（大王/小王）-0
	2. 要判断抽到的N张牌能否构成链子，直观的做法是对N张牌排序，
		然后再看其中有几张王，如果王的数量大于gap总数，返回true，否则返回false
*/

bool isContinuousPokerChain(vector<int> nums, int N){
	if(N < 3 || nums.size() < N)
		return false;
	int num_zero = 0;
	int num_gap = 0;
	// 默认从小到大排序
	sort(nums.begin(), nums.end());
	int idx_prev = -1;
	for(int i=0; i<nums.size(); i++){
		if(nums[i] == 0)
			num_zero++;
		else{
			idx_prev = i;
			break;
		}
	}
	int idx_next = idx_prev + 1;
	while(idx_prev != -1 && idx_prev < nums.size() && idx_next < nums.size()){
		if(nums[idx_prev] == nums[idx_next])
			return false;
		num_gap += nums[idx_next] - nums[idx_prev] - 1;
		idx_prev = idx_next;
		idx_next++;
	}

	return (num_gap <= num_zero ? true : false);
}

int main(int argc, char const *argv[])
{
	/* code */
	int N;
	cout << "N: ", cin >> N;
	vector<int> nums;
	int num;
	cout << "nums: ";
	do{
		cin >> num;
		if(num!=-1)
			nums.push_back(num);
	}while(num!=-1);
	cout << "isContinuousPoker: " << isContinuousPokerChain(nums, N) << endl;

	return 0;
}
