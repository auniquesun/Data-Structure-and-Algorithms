/*
problem：
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

idea：
这个题leetcode抽疯了，明明答案对了，leetcode run code 显示乱七八糟
提交答案还是对了

直观的做法，排序之后，判断当前元素是否在正确的位置，
如果不在，删除它，再把它素插入正确的位置，
*/

class Solution {
public:
    static bool compare(vector<int> v1, vector<int> v2){
        return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // people每个元素是个vector，其实这个vector只有两个元素，height和count
        // 按照 height从高到低，count从小到大排序
        sort(people.begin(), people.end(), compare);
        
        for(int i=0; i<people.size(); i++){
            vector tmp = people[i];
            if(people[i][1] != i){
                people.erase(people.begin() + i);
                people.insert(people.begin() + tmp[1], tmp);
            }
        }

        return people;
    }
};