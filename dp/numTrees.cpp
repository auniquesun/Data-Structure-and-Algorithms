/*
idea: 这其实是一道动态规划+找规律的题，
		一颗二叉搜索树，有n个节点，节点取值从1到n；
		首先这n个值肯定能填满二叉树，并且满足二叉搜索树的性质，所以就当它是一颗普通的树就行；
		除了空树，二叉树肯定有根节点（占用了1个），规律就是：
		左子树有0个节点，右子树有n-1个节点，
		左子树有1个节点，右子树有n-2个节点，
		左子树有2个节点，右子树有n-3个节点，
		...
		左子树有n-2个节点，右子树有1个节点，
		...

		然后动态规划计算即可，因为n==1,2,3时结果已经知道了
*/

class Solution {
public:
    int numTrees(int n) {
        if(n == 1)
        	return 1;
        if(n == 2)
        	return 2;
        if(n == 3)
        	return 5;

        int *nums = new int[n+1];	// 因为多了一个nums[0], 所以这里开辟了n+1个空间
        nums[0] = 1;
        nums[1] = 1;
        nums[2] = 2;
        nums[3] = 5;

        int sum = 0;
        for(int i=4; i<=n; i++){
        	nums[i] = 0;
        	for(int j=0; j<i; j++)
        		nums[i] += nums[j] * nums[i-1 - j];
        }
        int res = nums[n];
        delete [] nums;
        return res;
    }
};