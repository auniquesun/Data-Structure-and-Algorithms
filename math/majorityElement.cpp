#include <iostream>
#include <set>
#include <vector>
#include <climits>

using namespace std;

/*
	problem:
	给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

	你可以假设数组是非空的，并且给定的数组总是存在众数。

	示例 1:

	输入: [3,2,3]
	输出: 3
	示例 2:

	输入: [2,2,1,1,1,2,2]
	输出: 2

	idea:
	众数的出现次数 > 数组长度/2
	所以如果数组中存在众数，搜寻前一半元素，
	对其中每个元素依次计数，必定能找到这个众数，
	否则数组不存在众数
*/

class Solution {
public:
    // 这种方法时间复杂度为O(n)，要求数组中一定存在众数
    int advancedSolution(vector<int>& nums){
        int max_index = 0;
        int count = 1;  // 众数出现次数大于数组个数一半

        for(int i=1; i<nums.size(); ){
            if(nums[max_index] == nums[i])
                count++;
            else
                count--;

            if(count == 0){     // 这里的处理非常巧妙
                max_index = i;
                count = 1;
            }
        }

        return nums[max_index];
    }

    int majorityElement(vector<int>& nums) {
        set<int> S;

        if(nums.size() == 0)
            return -1;

        if(nums.size() == 1)
            return nums[0];

        for (int i = 0; i < (nums.size()/2 + 1); ++i)	// 根据众数的定义，它的出现次数要大于 nums.size()/2
        										// 如果众数存在，必定在前一半数中就能找到
        {
        	/* code */
        	if(S.find(nums[i]) == S.end()){	// 如果nums[i]不在集合S里，说明之前没对它计过数
        									// 此时才进行计数
        		int count = 0;
        		for (int j = 0; j < nums.size(); ++j)
        		{
        			/* code */
        			if(nums[j] == nums[i])
        				count++;
        		}
        		if(count > nums.size()/2)
        			return nums[i];
        	}

        	S.insert(nums[i]);

        }
        return -1;	// 如果能执行到这句，说明没找到众数
        
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> nums;
	int num;

	while(cin>>num)
	{
		nums.push_back(num);
		if(num == INT.MAX)
			break;
	}

	Solution *solu = new Solution();
	cout << "majorityElement of nums: " << solu->majorityElement(nums);
	return 0;
}
