#include<iostream>
#include<vector>
#include<climits>

using namespace std;

/*
reference：https://www.geeksforgeeks.org/quick-sort/

idea:
The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.
*/

int partition(vector<int> &nums, int left, int right, int &iteration){
    int i = left - 1;   //索引pivot的位置，默认它的位置为left-1，然后逐步改变
    int target = nums[right];

    for(int j=left; j<=right-1; j++){

        if(nums[j] <= target){
            i++;
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }

    int tmp = nums[i+1];
    nums[i+1] = nums[right];
    nums[right] = tmp;

    // cout << "iteration: " << iteration++ <<endl;
    // for(int k=0;k<nums.size();k++)
    //     cout<<nums[k]<<endl;

    return i+1; //返回nums[right]在数组中正确的位置
}

// divide and conquer 的思想
void quicksort(vector<int> &nums, int left, int right, int &iteration){
    if(left < right){
        int pivot = partition(nums, left, right, iteration);
        quicksort(nums, left, pivot-1, iteration);  
        quicksort(nums, pivot+1, right, iteration);
    }
}

int main(){
    cout << "INT_MAX: " << INT_MAX << endl << endl;
    vector<int> nums;
    int num=0;

    while(num!=INT_MAX){
        cin >> num;
        if(num!=INT_MAX)
            nums.push_back(num);
    }

    int left = 0;
    int right = nums.size()-1;

    int iteration = 0;
    //nums是引用传递，iteration为了在测试时使用
    quicksort(nums, 0, right, iteration);

    cout << "last" <<endl;
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<endl;
}