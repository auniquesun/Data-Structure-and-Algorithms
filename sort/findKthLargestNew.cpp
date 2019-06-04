#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        int target = nums[right];
        int i = left-1, j, tmp;

        for(j=left; j<right; j++){
            if(nums[j] >= target){
                i++;
                if(nums[i] != nums[j]){ // 把大于等于target的值移到target左边
                    tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }

        tmp = nums[i+1];
        nums[i+1] = nums[right];
        nums[right] = tmp;

        return i+1;
    }
    int solu1_quicksort(vector<int>& nums, int k, int left, int right){  // 找第k大的数，从大到小排序，
        if(k>0 && k<=right-left+1){
            int pivot = partition(nums, left, right);

            if(pivot - left == k - 1)   // 注意，这里 pivot 减的是 left，原来博客 里写的 l，很容易看成1
                return nums[pivot];
            else if(pivot - left > k - 1)   // 同上，减去的是 left
                return solu1_quicksort(nums, k, left, pivot-1);
            else
                return solu1_quicksort(nums, k-pivot-1 + left, pivot+1, right);    // 这时 k 的值要变了
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int result = solu1_quicksort(nums, k, 0, nums.size()-1);
        for(int i=0; i<nums.size(); i++)
            cout << nums[i] << " ";
        return result;
    }
};

int main(){
    Solution *solu = new Solution();
    int arr[] = {3,2,3,1,2,4,5,5,6};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));
    int k;
    cout << "k: ";
    cin>>k;
    cout << endl << solu->findKthLargest(nums, k) << endl;
}
