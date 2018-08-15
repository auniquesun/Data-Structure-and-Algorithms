#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	problem: 合并区间
	给出一个区间的集合，请合并所有重叠的区间。

	示例 1:

	输入: [[1,3],[2,6],[8,10],[15,18]]
	输出: [[1,6],[8,10],[15,18]]
	解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
	示例 2:

	输入: [[1,4],[4,5]]
	输出: [[1,5]]
	解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

	idea:
	（1）一种 naive 的方法是：以第一个区间作为基准，与剩余区间合并，把合并后的区间作为一个新的开始，重复上述过程
	（2）a.既然要合并区间，那就要判断不同区间起始坐标大小，区间有个特点就是左端点小于等于右端点
		 b.直观的方法是把所有区间按左端点大小排序，再判断相邻两个区间是否有交集，如果有交集，再决定是否合并
*/


/**
 * Definition for an interval.
 */
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    	vector<Interval> result;

    	if(intervals.size() > 0){

	        sort(intervals.begin(), intervals.end(), compare);	// 这里compare参数，是用户自定义的排序规则

	        Interval prev = intervals[0];
	        for (int i = 1; i < intervals.size(); ++i)
	        {
	        	/* code */
	        	Interval cur = intervals[i];	// 记录当前的 interval
	        	if(isIntersected(prev, cur)){	// 先确定prev和cur是否有交
	        		if(prev.end < cur.end)	// 确定有交集后，还必须判断这种情况，因为prev可能包含cur
	        								// 如果prev包含cur，就不能把 cur.end 赋值给 prev.end
	        			prev.end = cur.end;	// 合并区间，并不是产生一个新的interval，而是改变区间右端点的值
	        	}
	        	else{
	        		result.push_back(prev);
	        		prev = cur;
	        	}
	        }

			result.push_back(prev);	// 把最后一个prev放入result
    	}

    	return result;
    }

    static bool compare(Interval prev, Interval cur){	// compare 要定义成 静态方法
    	return prev.start < cur.start;	// 把intervals按照起始坐标升序排列
    }

    bool isIntersected(Interval prev, Interval cur){	// 判断两个区间是否有交
    	return prev.end >= cur.start;	
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	vector<Interval> intervals;

	while(true){
		int start, end;
		cin >> start >> end;

		if(start == 0 && end == 0)
			break;

		Interval it(start, end);
		intervals.push_back(it);

	}

	Solution *solu = new Solution();
	vector<Interval> result =  solu->merge(intervals);

	for(int i=0;i<result.size();i++)
    	cout << " " << result[i].start << "," << result[i].end << ")" << " ";
    cout << endl;

	return 0;
}