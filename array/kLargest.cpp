vector<int> kLarget(vector<int> nums, int k){
	vector<int> res;

	if(nums.size() > 0){

		for(int i=0; i<k; i++){
			int max = INT_MIN;
			for(int j=1; j<nums.size(); j++){
				if(res.find(nums[i]) == res.end() && max <= nums[i]){
					max = nums[i];
					res.push_back(max);
				}
			}
		}
	}

	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> nums;
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}

	vector res = kLarget(nums);
	for(int i=0; i<res.size(); i++){
		cout << res[i] << endl;
	}

	return 0;
}