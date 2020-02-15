#include "public.h"

/*
   写这个是为什么呢？
   1. 证明传递指针 *arr，被调用函数修改数组值，会体现在调用函数中的原数组
   2. 证明传递行参 arr[]，被调用函数修改数组值，会体现在调用函数中的原数组

    output:
    1 2 3 4 25 
    1 2 3 4 125
*/

void changeValue(int *arr, int n){
    arr[n-1] = arr[n-1] * arr[n-1];
}

void changeValue1(int arr[], int n){
    arr[n-1] = arr[n-1] + 100;
}

int main(){
    int arr[] = {1,2,3,4,5};
    changeValue(arr, 5);
    for(int i=0; i<5; i++)
        cout << arr[i] << ' ';
    cout << endl;
    changeValue1(arr, 5);
    for(int i=0; i<5; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
