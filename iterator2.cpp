#include<vector>
#include<iostream>

using namespace std;

/*
 *  problem: 给定一个数字n，有1，2，3...n的一个排列
 *              a. 输出第一个数字，并将他后面的数字放到排列末尾，
 *              b. 之后删掉第一数字
 *              c. 重复a，b步骤，直到每个元素都输出一遍
 *  idea: 我的想法是用一个迭代器指向排列头部，然后从头到尾扫描排列，
 *          该加的时候就加，该输出的时候就输出
 *          但是：事实表明c++的迭代器不能这么用，这么用的时候，
 *                  扫到最初的排列（没有增加额外元素，只有1，2，...，n按顺序排列）的末尾，
 *                  迭代器就乱了，并不能找到新添加元素的开头，这是c++迭代器使用的i<<<一个坑吧>>>
 * */
int main(){
	int n;
	cin >> n;
    int count = 0;
    
	vector<int> nums;
	for(int i=0; i<n; i++){
		nums.push_back(i+1);
	}
    vector<int>::iterator it = nums.begin(), jt;
    
	while(count < n){
        if(it!=nums.end())
            cout << "it: " << *it << " " <<endl;
        count += 1;
        
        cout << "jt: ";
        for(jt = nums.begin(); jt!=nums.end(); jt++)
            cout << *jt << " ";
        cout << endl;

        if(it!=nums.end())
            it++;
        else{
            cout << "它奶奶的 it 为空" << endl;
            break;
        }

        if(it!=nums.end())
            nums.push_back(*it);

        if(it!=nums.end())
            it++;
	}
}
