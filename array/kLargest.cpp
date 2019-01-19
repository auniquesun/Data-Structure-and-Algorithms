/*
problem: 返回一个数组中最大的k个数

idea：
1. 可以用排序的思想解决，排序后返回最大的连续k个
2. 第一种时间复杂度比较高，可以用选择排序的思想：
	a。每次选一个当前数组中最大的值，选出来之后将它删掉，
	b。继续从剩余元素中选最大值
*/

vector<int> kLarget(vector<int> nums, int k){
	vector<int> res;

	if(nums.size() > 0){

		for(int i=0; i<k; i++){		//用k次选择排序，每选一个最大值，
									// 将它删除掉，继续选剩余元素的最大值
			if(nums.size() > 0){
				int max_index = 0;	//记录数组中最大值的索引，初始化为0

				for(int j=1; j<nums.size(); j++){
					if(nums[max_index] < nums[j])
						max_index = j;
				}
				res.push_back(nums[max_index]);
				vector<int>::iterator it = nums.begin();
				nums.erase(it + max_index);
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