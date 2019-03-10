#include<vector>
#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> nums;
	for(int i=0; i<n; i++){
		nums.push_back(i+1);
	}

	while(nums.size() > 0){
		vector<int>::iterator it = nums.begin();
		cout << *it << " ";
		nums.erase(it);
		it = nums.begin();
		nums.push_back(*it);
		nums.erase(it);
	} 

	cout << endl;
}
