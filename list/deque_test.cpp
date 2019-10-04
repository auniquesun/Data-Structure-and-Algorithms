#include<iostream>
#include<deque>

using namespace std;

int main(){
    deque<int> dq;
    dq.push_front(10);
    dq.push_front(20);
    dq.push_front(30);
    deque<int>::reverse_iterator it;
    for(it=dq.rbegin(); it!=dq.rend(); it++)
        cout << *it << endl;
    int count = 0;
    while(count--){
        cout << count << endl;
    }
}
