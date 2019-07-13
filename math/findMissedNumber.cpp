#include<iostream>
#include<vector>

using namespace std;

/*
problem:
一个长度为n-1的数组nums，每个数字的取值都在[0, n-1]之间，
每个数字只出现一次，而且数组是从小到大有序的，
求问：[0,n-1]中的哪个数字不在nums中.
    要求时间复杂度为O(log(n)), 空间复杂度为O(1)

idea:
首先，不管会不会做这个题，数组有序，要往二分查找上想，
时间复杂度的要求更印证了这一点
其次，空间复杂度，只能开辟几个变量的空间

核心寻找第一个这样的数字，它的下标和对应的值不相等
*/

int findMissedNumber(vector<int> nums){
    int left = 0, right = nums.size() - 1;

    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] != mid){
            if(mid == 0 || nums[mid-1] == mid-1)
                return mid;
            else
                right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return -1;  // 表示没找到, 输入不符合要求
}

int main(){
    vector<int> nums={0,1,3,4};
    cout << findMissedNumber(nums) << endl;
}
