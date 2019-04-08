#include<iostream>
#include<algorithm>

using namespace std;

/*
problem：给定一个大小为n的数组arr，再给定一个整数k，重复k次如下操作：
        要求每次输出数组中最小的非0元素min，每个非0元素再减去min
        n的取值范围  1~10的九次方，k的取值范围 1<=k<=n

idea：  双重循环的方式不可取——k次外层循环，内层循环每次求n个元素的最小值，输出并减去该最小值

        这种题的做法一般不是暴力求解，要找规律，可以找到的规律就是——
            a。对原数组从小到大排序，这样做的好处是外层不用每次都求一遍最小值
            b。首先输出第一个元素，对于接下来的k-1个元素，如果
                b1. arr[i] != arr[i-1]，输出前后两个元素的差 arr[i] - arr[i-1]
                b2. arr[i] == arr[i-1]，此时不能输出 arr[i] - arr[i-1]，要
                    寻找之后第一个 arr[j] ！= arr[j-1] 输出，
                    如果没有的话，则表明后面的元素全相等，前后做差都为0，输出0即可

*/

int main(){
    int n, k;
    cout << "input n, k: ";
    cin >> n >> k;

    int val;
    int *arr = new int [n];
    cout << "input " << n << " values: ";
    for(int i=0; i<n; i++){
        cin >> val;
        arr[i] = val;
    }
    // 排序原数组
    sort(arr, arr+n);

    cout << arr[0] << endl;
    for(int i=1; i<k; i++){
        if(arr[i] != arr[i-1])
            cout << arr[i] - arr[i-1] << endl;
        else{
            int j = i;
            while(j < n && arr[j] == arr[j-1])
                j++;
            if(j<n)
                cout << arr[j] - arr[j-1] << endl;
            else
                cout << 0 << endl;
        }
        
    }
    delete [] arr;
}