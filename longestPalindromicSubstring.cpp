#include <iostream>
#include <string>
using namespace std;

// ======================== idea ========================
//一个回文子串，
//①长度有可能是--奇数，从左到右遍历输入字符串，继续向两头扩张回文子串，若满足扩张条件，记录扩张之后的长度，并与maxLen比较
//②也有可能是--偶数，从左到右遍历输入字符串，继续向两头扩张回文子串，若满足扩张条件，记录扩张之后的长度，并与maxLen比较



string longestPalindromicSubstring(string s){
	int maxLen = 1;		// 记录最长回文子串的最大长度
	int strLen = s.length();

	int start = 0;		// 记录最长回文子串的起始位置，因为要打印最终的最长回文子串
	int low,high;

	int i;
	// One by one consider every character as center point of 
    // even and length palindromes
	for(i=1;i<strLen;i++)	{		// 循环过程中i的值只在最外层循环更新，内部并没有更新
		// odd length palindromic substring
		low = i-1;
		high = i+1;
		while(low>=0 && high<strLen && s[low] == s[high])	{
				if(high - low + 1 > maxLen){
					start = low;
					maxLen = high - low + 1;
				}
				low--;
				high++;
		}

		// even length palindromic substring
		low = i-1;
		high = i;
		while(low>=0 && high<strLen && s[low] == s[high])	{
				if(high - low + 1 > maxLen){
					start = low;
					maxLen = high - low + 1;
				}
				low--;
				high++;
		}

	}

	char *result = new char [maxLen + 1];
	result[maxLen] = '\0';	// char数组结束符
	for(int j=0,i=start;i<start+maxLen;j++,i++)	
		result[j] = s[i];

	return result;
	
	//return maxLen;
}

int main(){
	string s;
	cout<<"input a string:"	;
	cin>>s;

	//cout<<"longest Palindromic Substring of s is: "<<longestPalindromicSubstring(s)<<endl;
	cout<<"longest Palindromic Substring of s is: ";
	cout<<longestPalindromicSubstring(s);
	cout<<endl;
}
