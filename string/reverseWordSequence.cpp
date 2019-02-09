#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseWordSequence(string str){
	vector<string> vec;
	string s = "";
	for(int i=0; i<str.length(); i++){
		if(str[i] != ' ')
			s += str[i];
		else{
			vec.push_back(s);
			s = "";
		}
	}
	string result = "";
	for(int i=vec.size()-1; i>0; i--)
		result += vec[i] + " ";
	result += vec[0];
	return result;
}

int main(int argc, char const *argv[])
{
	/* code */
    char ch[] = {'I',' ','a','m',' ','a',' ','s','t','u','d','e','n','t','.',' ','\0'};
	string str(ch);
	cout << "str: " << str << endl;
	cout << "reversed word sequence: " << reverseWordSequence(str);
	return 0;
}
