struct Interval{
    int start;
    int end;
    // 用参数列表初始化
    Interval(int s, int e):start(s), end(e) {}
}

class Solution{
    public:
    vector<vector<int>> mergeInterval(vector<vector<int>> &intervals){
        vector<vector<int>> result;

        if(intervals.size() > 0){
            sort(intervals.begin(), intervals.end(), compare);

            vector<int> prev = intervals[0], next;

            for(int i=1; i<intervals.size(); ++i){
                next = intervals[i];
                if(isIntersected(prev, next)){
                    // 为什么要比较这个呢，因为 prev.end>=next.end的时候，prev包含next，不用合并
                    // 只需要往后推next，prev保持不变，继续与后面的next合并；此时prev也不需要推入result
                    if(prev[1] < next[1])
                        prev[1] = next[1];
                }
                else{
                    // 两个区间没有交集
                    result.push_back(prev);
                    // 向后推移 prev
                    prev = next;
                }
            }
            result.push_back(prev);
        }

        return result;
    }

    // 从小到大排序
    static bool compare(vector<int> prev, vector<int> next){
        return prev[0] < next[0];
    }

    // 判断两个区间有没有交集
    bool isIntersected(vector<int> prev, vector<int> next){
        // 有共同的点就视作有交集
        return prev[1] >= next[0];
    }
};