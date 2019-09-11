// bad_alloc standard exception
#include <iostream>
#include <exception>
using namespace std;

int main () {
  try
  {
    int* myarray= new int[1000];
    delete [] myarray;
  }
  catch (exception& e)  // 注意这里 exception 是对象的引用
  {
    cout << "Standard exception: " << e.what() << endl;
  }
  return 0;
}