#include <iostream>
using namespace std;

int Judge(int data[], int mid, int m, int n); // 这里参数 mid 为假定的此划分的最大值，这个函数就是要判断是否存在满足这一假定的划分
int BinarySearch(int data[], int left, int right, int m, int n);


int main()
{
    int n = 0, m = 0;
    cin >> n >> m;

    int data[n];
    int max_num = 0;
    int sum = 0;

    int i = 0;

    for(i = 0; i < n ; i++)
    {
        cin >> data[i];
        if (data[i] > max_num)
        {
            max_num = data[i];
        }
        sum += data[i];
    }

    cout << BinarySearch(data, max_num, sum, m, n) << endl;

    return 0;
}

int BinarySearch(int data[], int left, int right, int m, int n)
{
    int mid = 0;

    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (Judge(data, mid, m, n)) //满足划分，继续向左寻找
        {
            right = mid; //继续向左寻找，看有没有更小的mid值
        }
        else    //不满足划分，继续向右寻找
        {
            left = mid + 1;
        }
    }

    return left;
}

int Judge(int data[], int mid, int m, int n)
{
    int cnt = 0; // 记录整个区间的划分次数，这个次数不能超过 m - 1，因为总共只有m个小区间
    int sum = 0; // 记录当前小区间所有正整数的和

    for (int i = 0; i < n; i++)
    {
        if (sum + data[i] > mid) //累加和大于 mid，进行一次划分，原因是：假定mid为整个划分的最大值
        {
            sum = data[i]; //把sum赋值为 data[i], 因为data[i]是新的小区间的第一个值
            cnt++; //整个区间划分次数要加1
            if (cnt > m - 1)    //划分次数大于 m-1,不满足划分
            {
                return 0;
            }
        }
        else
        {
            sum += data[i]; //表明当前小区间的正整数的和小于mid，不增加划分数cnt的值
        }
    }

    return 1;
}
