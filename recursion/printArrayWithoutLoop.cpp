#include<iostream>
#include<vector>

using namespace std;

void printElem(vector<int> nums, int i){
    if(i == nums.size()-1){
        cout << nums[i] << " " << endl;
        return;
    }
    printElem(nums, i+1);
    cout << nums[i] << " " << endl;
}
int main(){
    vector<int> nums;
    for(int i=0; i<10; i++)
        nums.push_back(i);
    printElem(nums, 0);
    cout << endl;
}
