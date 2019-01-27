#include<iostream>
#include <vector>
using namespace std;

void charsPermutation(vector< vector<char> > &result, vector<char> &chars, int begin){
	if(begin == chars.size())
		result.push_back(chars);

	for(int i=begin; i<chars.size(); i++){
		char temp = chars[i];
		chars[i] = chars[begin];
		chars[begin] = temp;

		//递归深入最顶层
		charsPermutation(result, chars, begin+1);	

		// 这几个步骤非常关键，上面交换了chars[i]，chars[begin]，
		// 又把它们换回来，下次循环让i++
		temp = chars[i];
		chars[i] = chars[begin];
		chars[begin] = temp;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<char> chars;
	chars.push_back('a');
	chars.push_back('b');
	chars.push_back('c');
	chars.push_back('d');
	chars.push_back('e');
	int begin = 0;	//从chars的第0个元素开始

    vector< vector<char> > result;
    charsPermutation(result, chars, begin);
    cout << "result size: " << result.size() << endl;
	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++)
			cout << result[i][j];
		cout << endl;
	}
	return 0;
}
