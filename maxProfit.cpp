#include<vector>
#include<utility>   //包含pair数据结构

using namespace std;

/*
problem:

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