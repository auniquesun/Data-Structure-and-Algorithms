#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
    //把一个数字转换为字符串
    int n;
    cin >> n;
    cout << "int: " << n << endl;
    istringstream iss("1 2 3");
    iss >> n;
    cout << n << endl;
    iss >> n;
    cout << n << endl;
    iss >> n;
    cout << n << endl;
    ostringstream oss;
    oss << 1 << "+" << 2 << "=" << 3 << endl;
    string str = oss.str();
    cout << "oss: " << str << endl;
    cout << "string: " << to_string(n) << endl;
}
