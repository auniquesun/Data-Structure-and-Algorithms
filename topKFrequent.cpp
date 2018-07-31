#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>	// map中的元素没有顺序之分

using namespace std;

/*
	problem：前K个高频元素

	给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

	例如，

	给定数组 [1,1,1,2,2,3] , 和 k = 2，返回 [1,2]。

	注意：

	你可以假设给定的 k 总是合理的，1 ≤ k ≤ 数组中不相同的元素的个数。
	你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

	idea：
	这里说的时间复杂度 必须优于 O(n log n)，这句话的理论依据值得考虑，
	因为排序算法的时间复杂度不会比 O(n log n) 更优

	（1）我首先想到了一种解法，是海量数据挖掘课程中学到的——水塘采样算法，
		但是在实践运用过程中发现这种解法不适用于这里，得到的解答错误，因为它是用来估计海量流数据中 top-K frequent item的，
		既能得到 top-K frequent item 具体的数目，也能得到 标记的 item，非常适合无限量的流数据，不适合有限的数据和精确的计数

	（2）建立一张映射表 ——（元素，计数值）
		按照计数值排列这些元组
		取 top-K
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;

        if(nums.size() != 0){
        	unordered_map<int,int> num2freq;	// 无序映射表，表中的元素没有先后之分
        	
        	for (int i = 0; i < nums.size(); ++i)
        	{
        		/* code */
        		num2freq[nums[i]]++;	// 对于值相同的nums【i】，frequency往上累加
        	}

        	vector< pair<int,int> > vec(num2freq.begin(), num2freq.end());	// pair<int,int> 这个语法还是首次用到

        	sort(vec.begin(), vec.end(), compare);	// 自定义排序规则，对于类库中提供的函数，一般都会有这样的接口

        	for (int i = 0; i < k; ++i)
        	{
        		/* code */
        		result.push_back(vec[i].first);
        	}
        }

        return result;
    }
    
    static bool compare(pair<int,int> p1, pair<int,int> p2){    // 需要设计成静态函数，不属于 Solution 类，否则不能再sort函数中调用
    	return p1.second > p2.second;	// 按照计数值 "降序" 排列
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {1,1,1,2,2,3};
	vector nums(arr,arr+6);

	Solution *solu = new Solution();
    vector<int> result = solu->topKFrequent(nums,2);

    for(int i=0;i<2;i++)
    	cout << result[i] << " ";
    cout <<endl;

	return 0;
}
