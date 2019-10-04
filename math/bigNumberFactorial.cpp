#include<iostream>
#include<deque>
#include<vector>

using namespace std;

deque<int> getFactorialResult(int n){
    deque<int> result;
    deque<int> product;
    int num = n--;
    //cout << "num: " << num << endl;
    int carry;
    int remain;
    int digit;

    // 初始化product
    while(num){
        product.push_front(num%10);
        num /= 10;
    }

    while(n>1){
        num = n;
        //cout << "num: " << num << endl;
        n -= 1;

        // 存放num中每个digit和product相乘的结果
        vector<deque<int>> intermediates;
        // 存放num中每个digit和product中每个digit相乘的结果：9x9,最大值为81
        deque<int> intermediate;
        // 记录是num的倒数第几个digit和product相乘
        int count = 0;
        while(num){
            int digit = num%10;
            num /= 10;

            carry = 0;
            for(int i=0; i<count; i++)
                intermediate.push_front(0);
            for(deque<int>::reverse_iterator r_it=product.rbegin(); r_it!=product.rend(); r_it++){
                int tmp = (*r_it) * digit + carry;
                remain = tmp%10;
                carry = tmp/10;
                intermediate.push_front(remain);
            }
            if(carry)
                intermediate.push_front(carry);
            intermediates.push_back(intermediate);
            //cout << "intermediate: ";
            //for(int i:intermediate)
            //    cout << i;
            //cout << endl;
            intermediate.clear();

            count++;
        }

        if(result.empty()){
            result.push_front(0);
        }
        // 对 intermediates 中的各个中间结果，按digit做加法
        for(auto intermediate:intermediates){
            deque<int>::reverse_iterator rit1 = intermediate.rbegin();
            deque<int>::reverse_iterator rit2 = result.rbegin();
            carry = 0;
            while(rit1 != intermediate.rend() && rit2 != result.rend()){
                int tmp = *rit2 + *rit1 + carry;
                *rit2 = tmp%10;
                carry = tmp/10;
                rit1++;
                rit2++;
            }
            // rit2 == result.rend() && rit1 != intermediate.rend()
            while(rit1 != intermediate.rend()){
                int tmp = *rit1 + carry;
                remain = tmp%10;
                carry = tmp/10;
                result.push_front(remain);
                rit1++;
            }
            // rit1 == intermediate.rend() && rit2 != result.rend()
            //while(rit2 != result.rend()){
            //    int tmp = *rit2 + carry;
            //    *rit2 = tmp%10; // 此时因为 rit2 还没有到达result.end()，所以直接给rit2赋值就行了，不用result.push_front
            //    carry = tmp/10;
            //    rit2++;
            //}
            if(carry)
                result.push_front(carry);
        }
        product = result;
        //cout << "result: ";
        //for(int i:result)
        //    cout << i;
        //cout << endl;
        result.clear();
        intermediates.clear();
    }

    return product;
}

int main(){
    int n;
    cout << "input N: ";
    cin >> n;
    deque<int> res = getFactorialResult(n);
    cout << "result.size: " << res.size() <<endl;
    cout << "result: ";
    for(int i:res)
        cout << i;
    cout << endl;
}
