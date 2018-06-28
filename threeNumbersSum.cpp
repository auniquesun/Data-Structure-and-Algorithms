#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<ctime>

using namespace std;

// ================ problem ==================
// 求一个数组中和为零的所有 三元组，不包含重复的三元组

// 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// ================ idea ==================
// 1. Sort all element of array
// 2. Run loop from i=0 to n-2.
//      Initialize two index variables l=i+1 and r=n-1
// 4. while (l < r) 
//      Check sum of arr[i], arr[l], arr[r] is
//      zero or not if sum is zero then print the
//      triplet and do l++ and r--.
// 5. If sum is less than zero then l++
// 6. If sum is greater than zero then r--
// 7. If not exist in array then print not found.


vector< vector<int> > threeSum(vector<int>& nums) {
    clock_t start = clock();

    //cout<<"start time: "<<float(start)/CLOCKS_PER_SEC<<endl;

    cout<<"start time: "<<float(start)<<endl;

    set< vector<int> > s;	// 准备插入满足条件的 triplet

    vector< vector<int> > result;     // 定义一个最终要返回的结果，嵌套向量，相当于二维向量

    vector<int> triplet;    // 定义每次循环找到的三元组

    int n = nums.size();    // 获取nums数组长度

    int i;

    sort(nums.begin(), nums.end());     // 从小到大排序vector元素

    for(i=0;i<n-1;i++){

        int left = i+1;

        int right = n-1;

        for(;left<right;){

            if(nums[i] + nums[left] + nums[right] == 0){    // nums[right] >= nums[left], 和为零表明有正有负

                triplet.push_back(nums[i]);

                triplet.push_back(nums[left]);

                triplet.push_back(nums[right]);
                s.insert(triplet);	// 集合中插入元素，不会有重复的元素，
                					// 这样后面就免去了去重这一步，时间效率进一步提高，通过了leetcode评判

                triplet.clear();

                right--;    // 必须再往下寻找，看是否有其他满足条件的值，否则跳不出循环

                //cout << opposite << " " << nums[i] << " " << nums[j] << endl;

            }

            else if(nums[i] + nums[left] + nums[right] < 0)

                left++;

            else

                right--;          

        }
    }

    //sort(result.begin(), result.end());

    //result.erase( unique( result.begin(), result.end() ), result.end() );   // 移除 result 中的重复元素

//    set< vector<int> > s( result.begin(), result.end() );

    result.assign( s.begin(), s.end() );	// 把 s 中的元素放入 result	

     //set<int> s;

     //for( i = 0; i < result.size(); ++i ) s.insert( result[i] );

	//result.assign( s.begin(), s.end() );



    clock_t end = clock();

    //cout<<"end time: "<<float(end)/CLOCKS_PER_SEC<<endl;

    cout<<"end time: "<<float(end)<<endl;

    cout<<"time cost is "<<float(end-start)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

    for(int i=0;i<result.size();i++){

        vector<int> row = result[i];

        for(int j=0;j<row.size();j++)

            cout << row[j] << " ";

        cout<<endl;

    }

    return result;
}

int main(){
    int arr[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> nums(arr, arr + n);

    threeSum(nums);
}
