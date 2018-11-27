/*
problem: 合并两个有序数组
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

idea: 这道题看似非常简单，但是也有几个坑
1. nums1是引用传递，而且函数返回值为void，所以最终的操作结果要体现在nums1上
2. nums1在插入或者删除的过程中，长度是动态变化的，循环条件要注意这种变化
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int j=0, i=0;j<n;){
            // 有两种情况，需要把nums2[j]插入nums1
            // 1. nums1[i]>nums2[j], 表明合并出现逆序，需要把nums2[j]插到nums1[i]之前
            // 2. 当nums1已经扫描到末尾，nums2还有元素，把nums2剩余元素逐个插入nums1
            if(nums1[i]>nums2[j] || i==m+j){
                vector<int>::iterator it = nums1.begin();//it需要初始化
                nums1.insert(it+i, nums2[j]);
                j++;
                i++;
            }
            else if(nums1[i]<=nums2[j])
                i++;
        }
        
        //删掉多余的元素；要灵活，这种情况从后往前删
        for(vector<int>::iterator it = nums1.end() - 1; nums1.size()>m+n; it--){    
            cout<< *it << endl;
            nums1.erase(it);
        }
            
    }
};