#include <vector>

/*
introduction: 希尔排序是对直接插入排序的改进

problem: 用希尔排序法，将数组nums从小到大排序

idea: 首先要理解直接插入排序的过程，当需要做很多次移动时，
    直接插入排序的效率和嵌套循环法接近
    其次，避免这种大量移动操作，希尔排序把数组切分成多个片段，
    每次排序使得每个片段内部有序；大的片段再做插入排序的时候，
    就不需要大量移动，当然少量移动是必须的
*/

void shellSort(vector<int> &nums){
    int n = nums.size();

    // 最外层的循环，变量gap可以来自用户输入，也可以用公式这么迭代
    for(int gap=n/2; gap>0; gap/=2)
    {
        for(int i=gap; i<n; ++i)
        {
            int tmp = nums[i];
            int j;
            for(j=i; j>=gap && nums[j-gap] > nums[j]; j-=gap)
                nums[j] = nums[j-gap];
            nums[j] = tmp;
        }
    }
}