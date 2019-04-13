/*
problem: Container With Most Water
            给定n个数，包含在一个数组里，分别代表容器的高度，求所有可能的容器中，装水最多的量

idea:  O(n*n) 的时间复杂度肯定能搜索出来，但是效率低

        寻找更优的解决方案，实际上 O(n) 的复杂度就能解决
        容器的底部——width，容器的高度——height，不管是什么容器，肯定有 left < right，且width <= n-1
        那就用 left++， right-- 的办法搜呗，并不断记录产生的最大值
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int max_area = 0, cur_area;
        while(left < right){
            cur_area = (right - left) * min(height[right], height[left]);
            max_area = max(max_area, cur_area);

            if(height[right] < height[left])
                right--;
            else
                left++;
        }

        return max_area;
    }
};