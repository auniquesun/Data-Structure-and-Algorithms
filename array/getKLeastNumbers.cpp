#include<iostream>
#include<cstdlib>
#include <vector>
#include<set>
using namespace std;

typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;

class Solution{
    public:
    int RandomInRange(int min, int max)
    {
        int random = rand() % (max - min + 1) + min;
        return random;
    }

    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    // 和快速排序中的partition函数一样，返回 target 在排序数组中特定的位置
    // nums 需要引用传递
    int partition(vector<int> &nums, int left, int right){
        int i = left - 1;
        //用随机数给出一个范围内的 index，最终目标是 返回nums[index]在排序数组
        //真实的位置
        int index = RandomInRange(left, right);
        swap(&nums[index], &nums[right]);

        for(int j = left; j<right; j++){
            if(nums[j] < nums[right]){
                i++;
                if(nums[i] != nums[j]){
                    swap(&nums[i], &nums[j]);
                }
            }
        }

        //把nums【right】放到 索引为 i+1 的位置，
        // i+1前面的元素都比nums【right】小，i+1后面的元素都比nums【right】大
        swap(&nums[i+1], &nums[right]);

        return i+1;
    }

    // 求数组中 k 个最小的数, // nums 需要引用传递
    void getKLeastNumbers(vector<int> &nums, int left, int right, int k){
        if(left < right){
            int index = partition(nums, left, right);
            cout << "index: " << index << endl;
            while(index != k){
                if(index < k)
                    left = index + 1;
                else
                    right = index - 1;
                index = partition(nums, left, right);
                cout << "index: " << index << endl;
            }
        }
    }

    void red_black_tree(vector<int> &nums, intSet &leastNumbers, int k){
        leastNumbers.clear();

        if(k<1 || k>nums.size())
            return;
        vector<int>::iterator it = nums.begin();
        for(; it != nums.end(); it++){
            if(leastNumbers.size() < k)
                leastNumbers.insert(*it);
            else{
                setIterator iterGreatest = leastNumbers.begin();
                if(*it < *iterGreatest){
                    leastNumbers.erase(iterGreatest);
                    leastNumbers.insert(*it);
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
	/* code */
    Solution *solu = new Solution();
	vector<int> nums;

	int K;
	cout << "K: ";	cin >> K;
	int val;
    cout << "input nums:" << endl;
	do{
		cin>>val;
		nums.push_back(val);
	}while(val!=1111111);

    /*cout << "solution one:" << endl;
	int left = 0, right = nums.size() - 1;
	solu->getKLeastNumbers(nums, left, right, K);

	for(int i=0; i<K; i++)
		cout << nums[i] << " ";
	cout << endl;
    */

    cout << "solution two:" << endl;
    intSet leastNumbers;
    solu->red_black_tree(nums, leastNumbers, K);
	for(setIterator it=leastNumbers.begin(); it!=leastNumbers.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}
