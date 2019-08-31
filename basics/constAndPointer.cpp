#include<iostream>

using namespace std;

int main(){

    cout << "int const a 和 const int a 等价 "  << endl;
    const int a=1;
    cout << "const int a=1 "  << a << endl;
    int const b=2;
    cout << "int const b=2 "  << b << endl;

    cout << "int const *c, 指针可变，指向的数不可变 "  << endl;
    int const *c = &a;
    cout << "c=&a "  << *c << endl;
    c = &b;
    cout << "c=&b "  << *c << endl;

    cout << "int *const d, 指针不可变，指向的数可变 "  << endl;
    int e = 3;
    int *const d = &e;
    cout << "e=3 "  << *d << endl;
    e = 4;
    cout << "e=4 "  << *d << endl;
}
