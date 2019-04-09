#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2idx;
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            num2idx[nums[i]] = i;
        }

        cout << "num2idx map: first, second" << endl;
        for(auto it=num2idx.begin(); it!=num2idx.end(); it++)
        	cout << it->first << " " << it->second << endl;

        for (int i=0; i < nums.size(); ++i) {
            int num = target - nums[i];
            if (num2idx.find(num) != num2idx.end() && num2idx[num] != i) {
                res.push_back(i);
                res.push_back(num2idx[num]);
                break;
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> nums;
	cout << "input vector nums: ";
	for(int i=0; i<2; i++){
		int val;
		cin >> val;
		nums.push_back(val);
	}

	int target;
	cout << "input target value: ";
	cin >> target;
	Solution *solu = new Solution();
	vector<int> result = solu->twoSum(nums, target);
    cout << "result: ";
    for(int i=0; i<result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

	return 0;
}
