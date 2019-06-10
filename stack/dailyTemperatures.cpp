/*
problem:
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

idea:
这个题我不知道难度在哪里，如果二重循环做的化，肯定是没有任何难度了
关键是要降低时间复杂度，那就是用空间换时间啦，开辟一个栈，而且是“递减栈”
栈里面存 temperature 的索引值，对应的 temperature 是递减的，
这样碰到一个比栈顶索引对应温度大的值，就立即能计算它们之间的距离了，
而且能保证这个距离 是比 T[descent_st.top()] 大的最短距离，
循环判断下去，直到栈为空，或者栈顶索引对应温度大于 当前温度T[i];
如果一开始就不满足循环条件，直接入栈即可
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        if(T.size() > 1){
            stack<int> descent_st;  // descent_st 存储天气的 index，知道index就能知道 temperature，而且temperature是递减的，即前面一个元素>=后面一个元素

            for(int i=0; i<T.size(); i++){
                while(!descent_st.empty() && T[descent_st.top()] < T[i]){   // 找到一个比栈顶索引值对应的温度大的 temperature
                    T[descent_st.top()] = i - descent_st.top();
                    descent_st.pop();
                }
                descent_st.push(i);
            }
        }
        return result;
    }
};