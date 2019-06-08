/*
problem:


idea:
这道题有个冷却期，卖完不能立即买（卖完的后一条不能买）
这就导致和前面买卖股票的解法不同，寻找局部最小和局部最大的pair

也是参考了别人的解法，有的解法确实不对，就在那儿抄来抄去没什么意思
想了一阵儿才明白到底是什么意思，肯定要用动态规划啦
开辟两个数组，一个叫作 buy[i]，另一个是 sell[i]
关键这两个数组代表什么意思，
buy[i]：第i天买股票，从第0天到第i天能赚到的最大收益
sell[i]：第i天卖股票，从第0天到第i天能赚到的最大收益
*/

class Solution {
public:
    // solution one
    int maxProfit_solu1(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int buy[prices.size()] ={0};
        int sell[prices.size()] = {0};
        // 这个题思想精妙的一个地方在于，上来第0天就买股票，那我的最大收益就是负的，因为这时候掏了钱，没有收入，很自然的事情
        buy[0] = -prices[0];
        // buy[1]的取值，意思是第1天买了，能赚取的最大收益；第1天之前是第0天，只能买，不能卖，因为没有股票卖不了东西，所以只能和buy[0]比较取最大值
        buy[1] = max(buy[0], -prices[1]);
        // 第0天没东西可卖，卖货赚取的最大收益为0
        sell[1] = max(0, buy[0] + prices[1]);
        for(int i=2; i<prices.size(); i++){
            buy[i] = max(buy[i-1], sell[i-2] - prices[i]);  // 截止到sell[i-2]，收益>=0，第i天要买入，这部分是支出的prices[i]，所以要用 “减法”
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]); // 第i天要卖出，在原来的基础上，收入prices[i]，所以要用 “加法”
            // 总之啊，这道题动态规划迭代的时候，思路很清楚，买就要出钱，就要做减法；卖就要往回拿钱，就要做加法
        }
        return sell[prices.size()-1];
    }
    // solution two，优化 solution one，将空间复杂度 降到 O(1)，很显然 solution one 里头迭代的数组可以用两个变量表示
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int preBuy = INT_MIN, curBuy = INT_MIN;
        int preSell = 0, curSell = 0;
        
        for(int i=0; i<prices.size(); i++){
            preBuy = curBuy;
            curBuy = max(preBuy, preSell - prices[i]);
            preSell = curSell;
            curSell = max(preSell, preBuy + prices[i]);
        }
        return curSell;
    }
};