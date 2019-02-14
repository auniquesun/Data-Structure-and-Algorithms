/*
problem：
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

idea:
这个题是典型的动态规划思想，要另外开辟一个与prices长度相同的新数组，
新数组第i个位置存放 长度为i的数组中最小的元素值，
然后让原数组与新数组 对应位置做减法，取最大值返回
*/

class Solution {
public:
    // 方案一
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        else{
            int min = prices[0];
            vector<int> prices_min; //元素个数与prices相同，prices_min[i]记录长度i+1的数组中最小值是多少
            prices_min.push_back(prices[0]);

            for(int i=1; i<prices.size(); i++){
                if(prices[i] < min)
                    min = prices[i];

                prices_min.push_back(min);
            }

            int max_profit = 0; //最后返回的最大收益
            vector<int> interval;   //元素个数与prices_min相同，interval[i]存储 prices[i] - prices_min[i]
            for(int i=0; i<prices.size(); i++){
                if(prices[i] - prices_min[i] <= 0)  //若小于0，置0
                    interval.push_back(0);

                else
                    interval.push_back(prices[i] - prices_min[i]);

                if(max_profit < interval[i])
                    max_profit = interval[i];
            }

            return max_profit;
        }
    }
    // 方案二：对方案一进行改进，方案一额外开辟了prices_min和interval两个数组
    // 实际上不需要开辟这两个数组就能解决问题
    int maxProfitAdvanced(vector<int>& prices){
        if(prices.size()<2)
                        return 0;
        else{
            int max_profit = 0; //实时跟踪最大利润
            int min_price = prices[0];  //实时跟踪最小价格
            // 并没有开辟额外的数组空间，只用了两个遍量
                        
            for(int i=1; i<prices.size(); i++){
                if(prices[i] < min_price)
                    min_price = prices[i];
                if(prices[i] - min_price > max_profit)
                    max_profit = prices[i] - min_price;
                                                            
            }
            return max_profit;
                                                        
        }
    }
};
