/*
problem: 实现堆排序算法

idea：
堆排序时首先要搞清楚
a. 什么是（二叉）堆？
b. 堆分为哪几类？有什么特点？
c. 堆排序的过程

a和b应该是基本的点，重点难点是堆排序的过程
	二叉堆是一颗完全二叉树，树节点的值不大于（不小于）左右子节点的值
	堆的存储实际上不是用 结构体{value + left pointer + right pointer}，
		而是用数组来存的，因为完全二叉树的结构完全能用数组来表示
	根据问题分析应该采用最大堆还是最小堆
step1：构建堆
step2：把堆顶元素同数组末尾元素交换
step3：repeat step1 and step2，直到当前数组只剩一个元素
*/

void swap(int &a, int &b){
	int tmp = a;
	int a = b;
	int b = tmp;
}

void heapify(vector<int> &nums, int n, int largest){
	// 默认largest为最大元素原始位置，用i标记这个原始位置
	// 因为后续largest的值可能被修改
	int i = largest;
	int left = 2*i+1, right = 2*i+2;

	if(left < n && nums[left] > nums[largest])
		largest = left;
	if(right < n && nums[right] > nums[largest])
		largest = right;

	if(largest != i)	// 说明largest被修改
	{
		// 把真正的largest放到默认位置
		swap(nums[i], nums[largest]);	
		// 因为largest已经改变过了，继续进入largest为根的子树进行堆化操作
		heapify(nums, n, largest);		
	}
}

void heapsort(vector<int> &nums){
	int n = nums.size();

	// step1: 构建堆
	// 用最大堆，最终实现的效果是从小到大排序，
	// 用最小堆，最终实现的效果是从大到小排序
	// 原因是最大堆要用根节点和最后一个元素交换，
	// 相当于么次最大的元素被放到了数组末尾
	for(int i=n/2-1; i>=0; i--){
		heapify(nums, n, i);
	}

	for(int i=n-1; i>0; i--){
		// step2: 把堆顶元素同数组末尾元素交换
		// heapify构建的是最大堆，堆顶元素就是根节点，值最大
		// 把堆顶元素同数组末尾元素交换
		swap(nums[0], nums[i]);

		// step3: repeat step1 and step2
		// 交换之后最大堆结构被破坏，重新构建堆
		heapify(nums, i, 0);
	}
}
