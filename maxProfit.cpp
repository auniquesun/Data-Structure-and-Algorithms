#include<vector>
#include<utility>   //包含pair数据结构

using namespace std;

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