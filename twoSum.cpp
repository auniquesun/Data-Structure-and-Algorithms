#include <vector>

using namespace std;

/*
problem:
两数之和
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

idea:
	根据题意，每对输入都会只有一种答案，且同一元素不会被重复利用
	所以对于每一组输入，向量都不为空，都有一个合理的答案

1. 这道题是要返回数组中元素的位置，所以不能对元素从小到大排序，
如果非要排序，会增加时间复杂度，还要用额外的空间标记元素原来的位置，
我最开始就是这么做的，对原素组排序，以减少不必要的循环次数，
后来证明这么做多余了
2. 一个简单有效的做法是用嵌套循环扫描数组，判断内外层循环元素之后
是否为target
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;

		if(nums.size()>0){
			for(int i=0;i < nums.size()-1;i++){
				for(int j=i+1;j < nums.size();j++){
					if(nums[i] + nums[j] == target){
						result.push_back(i);
						result.push_back(j);
						i = j = nums.size();	// 结束循环
					}
				}
			}
		}
		return result;
    }
};

int main(){
	int target;
	cout << "input target: ";
	cin >> target;


	vector<int> v;
	int num;
	cout << "input vector nums: ";
	while(cin>>num)
		v.push_back(num);

	Solution *solu = new Solution(v, target);
	vector result = solu->twoSum();
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<" ";
	cout<<endl;
}