#include<iostream>

using namespace std;

// 传递数组名，被调用函数里面修改的值会反映到调用函数
// 传递数组名，相当于传递指针，指针的值是数组第一个元素的地址
void modify_one(int arr[], int n){
    arr[0] = 0;
    cout << "in modify_one function" << endl;
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 传递指针，被调用函数里面修改的值会反映到调用函数
void modify_two(int *arr, int n){
    arr[0] = 6;
    cout << "in modify_two function" << endl;
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "first time: in main function" << endl;
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    //modify_one(arr, n);
    modify_two(arr, n);

    cout << "second time: in main function" << endl;
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
