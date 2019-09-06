#include<iostream>
#include<iomanip>       // iomanip的意思就是，input、output的manipulation，包含setprecision, fixed

using namespace std;

int main(){
        double num = 3.141592657345;

        // 可以分行输入，也可以放在一行
        cout << setprecision(10);
        cout << num << endl;
        cout << fixed;
        cout << setprecision(15) << num << endl;
}
