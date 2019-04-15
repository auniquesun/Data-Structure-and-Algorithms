#include <algorithm>
#include <vector>

/*
problem: 给定一个字符串，按从小到大的顺序，求它的下一个排列

idea:
    1. Find largest index i such that array[i − 1] < array[i].
    (If no such i exists, then this is already the last permutation.)

    2. Find largest index j such that j ≥ i and array[j] > array[i − 1].

    3. Swap array[j] and array[i − 1].

    4. Reverse the suffix starting at array[i].
*/
using namespace std;
class Solution{
    public:
    void nextPermutation(vector<int> &nums) {
        // Find non-increasing suffix
        if (nums.empty())
            return;
        vector<int>::iterator i = nums.end() - 1;
        while (i > nums.begin() && *(i - 1) >= *i)
            --i;
        if (i == nums.begin()){
            sort(nums.begin(), nums.end());
            return;
        }
            

        // Find successor to pivot
        vector<int>::iterator j = nums.end() - 1;
        while (*j <= *(i - 1))
            --j;
        iter_swap(i - 1, j);

        // Reverse suffix
        reverse(i, nums.end());
        return;
    }
    
};
