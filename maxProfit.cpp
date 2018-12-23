#include<vector>
#include<utility>   //包含pair数据结构

using namespace std;

/*
problem: 买卖股票的最佳时机 II
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

idea:
这道题其实不太好想，其核心的思想是：
要向赚取收益，一定要有buy、sell这一对操作，而且sell value > buy value才会有正收益
    从左往右扫面数组，
        寻找局部最小的点，即为buy点；
        从buy点之后，继续寻找局部最大的点，即为sell点；
        过程中要注意buy点最多扫面到数组倒数第二个元素；
        如果数组递减，则没有正收益，收益最大为0
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector< pair<int, int> > buy_sell_index_pair;        

        if(prices.size() < 2)
            return 0;
        else{
            pair<int, int> p;
            int n = prices.size();
            for(int i=0; i<n-1;){   //i<prices.size()-1是因为先要找buy点，buy点之后还有个sell点，buy点不能是最后一个元素
                while(i+1<n && prices[i]>=prices[i+1])
                    i++;
                
                if(i+1==n)
                    break;

                //没有break掉的话，就找到了局部最小，即 buy 的开始
                p.first = i;
                i++;    //找到 buy index后，i往后移动一下

                while(i+1<n && prices[i]<=prices[i+1])
                    i++;

                // 找到局部最大，也就是 sell 的点
                p.second = i;
                buy_sell_index_pair.push_back(p);

                //继续寻找下一个buy点
                i++;
            }

            int max_profit = 0;
            for(int i=0; i<buy_sell_index_pair.size(); i++)
                max_profit += prices[buy_sell_index_pair[i].second] - prices[buy_sell_index_pair[i].first];

            return max_profit;
        }
    }
};