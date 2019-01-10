/*
problem: 寻找两个有序数组的中位数
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

idea:
不开辟额外空间的解法，直接从小到大扫描nums1，nums2，
扫描到 (len1+len2)/2 的时候，判断奇偶
返回中位数
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        if(len1 == 0){
            if(len2%2 == 0)
                return (nums2[len2/2-1] + nums2[len2/2])/2.0;
            else
                return double(nums2[len2/2]);
        }
        if(len2 == 0){
            if(len1%2 == 0)
                return (nums1[len1/2-1] + nums1[len1/2])/2.0;
            else
                return double(nums1[len1/2]);
        }
        
        if(len1 == 1 && len2 == 1)
            return (nums1[0] + nums2[0])/2.0;
        
        int flag;
        if((len1+len2)%2 == 0)  //总长度为偶数
            flag = 0;
        else    //总长度为奇数
            flag = 1;

        int count = 0;  // 记录从小到大扫面了多少个数字，扫描到 len(+len2)/2 就该判断了，因为是从小到大扫面的

        int former, latter;
        int i,j;
        cout<<"latter: "<<latter<<endl;
        for(i=0, j=0; i<nums1.size() && j<nums2.size(); ){
            if(nums1[i] < nums2[j]){
                former = nums1[i];
                i++;
            }
            else{
                former = nums2[j];
                j++;
            }

            if(i<nums1.size()&&j<nums2.size()){
                if(nums1[i] < nums2[j])
                    latter = nums1[i];
                else
                    latter = nums2[j];                
            }
                
            count++;
            cout<<"count: "<<count<<" "<<former<<" "<<latter<<endl;
            if(count == (len1+len2)/2)
                break; 
        }
        
        while(count <= (len1+len2)/2){  //这里条件是 ”小于等于“，等号很重要
            if(i == len1){
                former = latter;
                latter = nums2[j];
                j++;
            }
            if(j == len2){
                former = latter;
                latter = nums1[i];
                i++;
            }
            count++;
        }

        if(flag == 0)
            return (former + latter)/2.0;
        else
            return latter;
    }
};