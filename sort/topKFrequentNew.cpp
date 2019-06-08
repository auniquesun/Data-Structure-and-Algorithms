#include <queue>	// priority_queue

/*

idea:
首先对每个元素计数，计完数不基于计数排序，
而是用特殊的数据结构，更快得到 k frequent，
这里用到了优先队列，基于大顶堆实现，每次取堆顶元素，
取k次，就得到了k frequent

时间复杂度，O(n + k*logd)，d是nums中不同元素的个数, n是数组元素个数，
            初始化 pq 也用时间了，没算在里面
空间复杂度，O(n+n), num2freq和pq各占用n个
*/
// 注意 compare 的写法
struct compare{
    bool operator() (pair<int,int> p1, pair<int, int> p2){
        return p1.second < p2.second;   // 特别注意，容易搞反：frequent从小到大排序，建立大顶堆
    }
};

class Solution {
    public:
    	// sort的比较函数也可以这么写
    	// static bool compare (pair<int,int> p1, pair<int, int> p2){
	    //     return p1.second < p2.second;   // 特别注意，容易搞反：frequent从小到大排序，建立大顶堆
	    // }
        vector<int> topKFrequent(vector<int>& nums, int k) {
            vector<int> result;
            if(nums.size()>0){
                unordered_map<int,int> num2freq; // 无序映射表，表中的元素没有先后之分
                for (int i = 0; i < nums.size(); ++i){
                	if(num2freq.find(nums[i]) == num2freq.end())
                		num2freq[nums[i]] = 1;
                	else
                    	num2freq[nums[i]]++; // 对于值相同的nums【i】，frequency往上累加，初值默认为0
                }

                // priority_queue 实现了大顶堆，pq.top()是最大元素，pop之后仍要保持大顶堆的性质
                priority_queue< pair<int,int>, vector< pair<int,int> >, compare> pq(num2freq.begin(), num2freq.end());

                for(int i=0; i<k && !pq.empty(); i++){
                    result.push_back(pq.top().first);
                    pq.pop();
                }
            }
            return result;
        }
};
