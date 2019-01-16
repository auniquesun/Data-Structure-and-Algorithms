#include<iostream>
using namespace std;

/*
problem：
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

idea:
这个题的关键在于分析每一次爬楼方案由哪些部分构成，不难发现
path[i] = path[i-1] + path[i-2], i>2
paths[0] = 1;   // 达到第一级台阶有1种上法
paths[1] = 2;   // 达到第二级台阶有2种上法

接下来可以选用递归的思想，动态规划的具体做法其实也是动态规划的思想，
只不过是把中间结果存下来，节省时间/空间开销
*/

class Solution {
public:

    // int fib(int n) 
    // { 
    // if (n <= 1) 
    //     return n; 
    // return fib(n-1) + fib(n-2); 
    // } 
    
    // // Returns number of ways to reach s'th stair 
    // int countWays(int s) 
    // { 
    //     return fib(s + 1); 
    // } 
    
    int climbStairs(int n) {
        // 递归的解法：消耗的空间和时间大，不能题目满足要求
        // return countWays(n);

        // 动态规划，把中间结果存放在数组，后期直接取用，比递归的优势是节省空间和时间
        if(n < 3)
            return n;

        int *paths = new int [n];
        paths[0] = 1;   // 达到第一级台阶有1种上法
        paths[1] = 2;   // 达到第二级台阶有2种上法
        for(int i=2;i<n;i++)
            paths[i] = paths[i-1] + paths[i-2];

        return paths[n-1];

    }
};

int main(){
    int n;
    cout << "n layers: " ;
    cin>>n;
    Solution *solu = new Solution();
    int ways = solu->climbStairs(n);
    cout << ways << endl;
}