#include<iostream>
#include<vector>

using namespace std;

/*
problem：在一个旋转数组中，找出最小值并返回
        什么是旋转数组呢？比如，【3,4,5,1,2】是【1,2,3,4,5】的一个旋转数组
                            【1,2,3,4,5】也是【1,2,3,4,5】的一个旋转数组
                            【1,0,1,1,1】和【1，1，1，0,1】都可以看成【0，1,1,1，】的旋转数组

idea：找最小值，O（n）的方法就不说了，肯定不是最好的解法，没用到递增的性质
        数组递增，不管怎样也要尝试二分搜索的方法，O（logN)
        把数组一切为二， 以旋转点为切分点：
        1. left, 跟踪左边的递增数组
        2. right，跟踪右边的递增数组
        3. mid = (left+right)/2, 
            nums[mid]要么大于nums[left]，==> 最小值在left右边
            要么小于nums[right] ==> 最小值在right左边
*/

int searchInOrder(vector<int> values){  //能进入这个函数，表明values中元素个数大于0
    int min = values[0];
    for(int i=1; i<values.size(); i++)
        if(min>values[i])
            min = values[i];
    return min;
}

int minValueInRotatedArray(vector<int> values){
    if(values.size() > 0){
        int left = 0;
        int right = values.size() - 1;
        int mid = left;
        while(values[left] >= values[right]){
            if(right - left == 1){
                mid = right;
                break;
            }
            int mid = (left + right) / 2;
            if(values[left] == values[mid] && values[mid] == values[right])
                return searchInOrder(values);
            else if(values[mid] >= values[left])
                left = mid;
            else if(values[mid] <= values[right])
                right = mid;
        }
        return values[mid];
    }else{
        cout << "empty vector values" << endl;
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = {2,3,4,5,1};
    vector<int> values(arr, arr+5);
    cout << "min: " << minValueInRotatedArray(values) << endl;

    return 0;
}
