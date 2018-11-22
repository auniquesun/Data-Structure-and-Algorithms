/*
problem: 盛最多水的容器
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

idea:
其实想法很简单，要寻找面积最大的矩形区域，
最暴力的方法就是 -- 遍历每一种可能，选出一个最大的，时间复杂度为O(n^2)
                  
因为垂线的位置是固定的，不能对高度进行排序
没想到更快速的方法                  
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, area = 0;
        for(int i=height.size()-1;i>0;i--){ //外层循环从后往前扫面
            for(int j=0;j<i;j++){   //内层循环从前往后扫面，与外层循环形成一个矩形区域
                if(height[i]>height[j])
                    area = height[j] * (i-j);
                else
                    area = height[i] * (i-j);
                if(area > max_area)
                    max_area = area;
            }
        }
        return max_area;    //如果高度全为0，那么返回的 max_area 也为0
    }
};