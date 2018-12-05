#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    double y, accuracy;
    cout << "input y, accuracy: ";
    cin >> y >> accuracy;

    int left = 0, right = y;
    int mid = (left+right)/2;

    while(left<=right){
        if(mid*mid == y)
            break;
        else if(mid*mid < y)
            left = mid + 1;
        else
            right = mid-1;

        mid = (left+right)/2;
    }

    cout << "result: " << mid << endl;
    return 0;
}
