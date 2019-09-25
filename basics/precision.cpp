#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    float num = 1.234;
    // setprecision中的参数，指小数点后的精度
    cout << fixed << setprecision(5) << num << endl;
}
