/*
problem: 在一个排序数组中找出 target 第一次和最后一次出现的位置
            如果没有，返回【-1，-1】
            要求时间复杂度为 O(logN)

idea：肯定用二分搜索啦，一次性找到 first，last并不容易
        用两次二分搜索，分别找first和last，
        复杂度仍为 O(logN)
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        
        // 找 first element
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
               result[0] = mid;
               right = mid - 1; // 向左搜索，并不关心右边的元素啦
            }
            else if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
        }

        // 找 last element
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
               result[1] = mid;
               left = mid + 1;  // 向右搜索，并不关心左边的元素啦
            }
            else if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
        }

        return result;
    }
};