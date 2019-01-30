#include<iostream>
#include <vector>
using namespace std;

/*
problem: 给定一个字符串，求该字符串中长度最大子串，要求子串没有重复元素
			给出符合要求的最长子串及其长度

idea：
	a. 时间复杂度为 O(n*n) 的解法就不考虑了，
	b. 动态规划的做法，
		b1. 开辟一个数组pos，元素个数为可能出现的字符个数，比如只出现26个英文小写字母，
			pos[str(i)] 记录 str(i) 上一次出现在string的位置，相对于现在扫描到的str(i)而言
		b2. 再开辟一个长度==string.length的数组 arr，
		arr【i】表示以 string【i】结尾的最长子串的长度，
		b3. 最后从arr中选取一个最大值，在打印该字符串
	c. 方案 b 解法还算可以，但是还有更好的，不用开辟数组arr，但是需要 pos
		只记录 max_len, max_index, cur_len 照样可以 求解
*/

vector<int> longestUniqueSubstring(vector<char> string){
	vector<int> result;
	if(string.size() > 0){
		// 1、 max_len 存储最长 substring 的长度
		// 2、 max_index 存储一个字符索引，这个字符索引指向一个字符，
		// 以该字符为结尾的 substring 长度最长
		// 结合1、 2，就能知道 substring 是什么
		int max_len = 0, max_index = -1;
		int cur_len = 0;

		// 假设字符串中只出现26个小写英文字母
		// 用 previous_pos【 string[i] - 'a' 】 存储：
		// string[i] 在string上一次出现的位置
		int *previous_pos = new int[26];
		for(int i=0; i<26; i++)
			previous_pos[i] = -1;

		for(int i=0; i<string.size(); i++){
			int prev_index = previous_pos[string[i]-'a'];
			if(prev_index == -1 || (i - prev_index) > cur_len)
				cur_len++;
			else{
				if(cur_len>max_len){
					max_len = cur_len;
					max_index = i;
				}
				cur_len = i - prev_index;
			}
            previous_pos[string[i] - 'a'] = i;
    	}
		if(cur_len>=max_len){//好多坑啊，这里要取等号，不取等号对max_len没什么影响，但是max_index就受影响了
			max_len = cur_len;
			max_index = string.size()-1;
		}
		result.push_back(max_len);
		result.push_back(max_index);
	}
	return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<char> string;
	char ch;
	do{
		cin>>ch;
		if(ch!='#')
			string.push_back(ch);
	}while(ch!='#');

    cout << "origin string: ";
    for(int i=0; i<string.size(); i++)
        cout << string[i];
    cout << endl;

	vector<int> result = longestUniqueSubstring(string);
	if(result.size()>0){
		cout << "max_len of substring: " << result[0] << endl;
		cout << "max_index of substring: " << result[1] << endl;
		cout << "reversed max_len substring: ";
		for(int i=result[1]; i>result[1]-result[0]; i--)
			cout << string[i];
		cout << endl;
	}
	return 0;
}
