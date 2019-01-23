#include<iostream>
#include<vector>
using namespace std;

/*
 * problem: 把一个数组里的0值移动到数组末尾, 非0值要保证相对顺序不变
 *
 * idea: naive method is 开辟一个新的数组，从头到尾扫描原元素，依次把非0值放到新数组开头
 *          很明显这样做空间开销很大
 *      现在想要的办法是 in-place method，
 *          a. 从头到尾扫描原数组，遇到第一个0值，将它与后面第一个非0值交换，
 *          直到0值后面没有非0值；
 *          b. 这样问题就很清晰了，关键是如何高效的寻找
 *          0值后面的非0值，解决办法是首先找出这样的位置，用一个变量index记录下来，
 *          下次找非0值的时候直接从index后面的元素找
 * */

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void moveZeroToEnd(vector<int> &nums){
	int index = -1;	//记录0元素后面第一个非0元素的位置
	for(int i=0; i<nums.size(); i++){	
		if(nums[i] == 0){	//找到第一个0元素
			int j = i+1;
			while(j<nums.size() && nums[j] == 0)	//找到第一个0元素后第一个非0元素
				j++;
			if(j<nums.size()){
				index = j;
				break;
			}
		}
	}

	for(int i=0; i<nums.size(); i++){
		if(nums[i] == 0){	//寻找i位置后的第一个非零元素
			if(index != -1 && index < nums.size()){
				swap(nums[i], nums[index]);
				int j = index+1;	//直接从index后的位置找，不用再从i后的位置找，节省了时间
				while(j<nums.size() && nums[j] == 0)	//跳过nums[i]后的零元素
					j++;
				if(j<nums.size())	//表明找到了nums[i]后的非零元素，与nums[i]交换
					index = j;
			}
		}
	}
}

int main(){
	vector<int> nums;
	nums.push_back(2783);
	nums.push_back(0);
	nums.push_back(23);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(5);
	nums.push_back(2);
	nums.push_back(0);

	moveZeroToEnd(nums);

	for(int i=0; i<nums.size(); i++)
		cout << nums[i] << endl;
}
