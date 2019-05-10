/*
problem: Given n non-negative integers representing the 
histogram's bar height where the width of each bar is 1, find the 
area of largest rectangle in the histogram

idea:
1. 创建一个空栈 S
2. 从第一个bar开始，对每个bar hist[i]进行如下操作:
	a. 如果栈为空，或者hist[i] >= hist[S.top()]
		把 i 进栈
	b. else，移除栈顶元素tp，直到 hist[i] >= hist[S.top()]；
		计算以 hist[tp] 为最低高度的 rectangle 面积
		如果大于最大面积，更新最大面积
3. 退出循环，如果栈非空，一个个移除栈顶元素，然后进行2.b操作
4. 返回最大 rectangle area		
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> S;

        int max_area = 0;	// 初始化最大面积
        int top;	// 存储栈顶元素
        int area_with_top; // 存储以hist[top]为高的区域的面积

        int i = 0;
        while(i < heights.size()){
        	if(S.empty() || heights[S.top()] <= heights[i])
        		S.push(i++);	// push之后，i要自增

        	else{	// 这种情况表明栈非空，heighs[S.top()] > heights[i]
        			// 相当于找到了 heights[i] 比栈顶 bar高度小，
        		top = S.top();
        		S.pop();

        		// 那么以 height[top] 为最小高度，求面积
        		area_with_top = heights[top] * (S.empty()?i:i-S.top() - 1);

        		if(max_area < area_with_top)
        			max_area = area_with_top;
        	}
        }

        while(!S.empty()){
        	top = S.top();
        	S.pop();

        	area_with_top = heights[top] * (S.empty()?i:i-S.top()-1);

        	if(max_area < area_with_top)
        		max_area = area_with_top;
        }
        return max_area;
    }
};