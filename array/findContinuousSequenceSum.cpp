#include <iostream>
#include <vector>
using namespace std;
/*
 * problem: 给定一个正整数sum，求所有的连续正整数序列，
 * 每个连续正整数序列的和为sum，要求序列中至少包含两个元素
 *
 * idea：small <= sum/2
 *
 */
vector< vector<int> > findContinuousSequenceSum(int sum){
	vector< vector<int> > result;
	if(sum >= 3){
		int small = 1, big = 2;
        // 因为序列至少包含两个元素，所以small<=(sum/2)
		int middle = sum/2;
		int cur_sum = small + big;

		while(small <= middle){
			if(cur_sum == sum){
				vector<int> sequence;
				for(int i=small; i<=big; i++)
					sequence.push_back(i);
				result.push_back(sequence);
				sequence.clear();
			}
			while(cur_sum < sum){
				big++;
				cur_sum += big;
			}
			cur_sum -= small;
			small++;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	int sum;
	cout << "sum: ";
	cin >> sum;
	vector< vector<int> > result = findContinuousSequenceSum(sum);
	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}
