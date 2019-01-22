#include<iostream>
#include<cstring>   // strlen
using namespace std;
/*
problem： 给定一个字符串str，再给定一个正则表达式 pattern，
	判断 str 是否与 pattern 匹配，匹配返回true，否则返回false

	例： str = aaa, pattern = a*		因为*代表前面的字符出现任意多次，
		包括0次，所以返回true

		str = aba，pattern = a.a 	因为 . 代表任意字符，所以str与
		pattern匹配，返回true

		str = abcd，pattern = ab*d，无论如何都不匹配，返回false

idea：
这道题的关键在于分析清楚pattern中'*'和'.'出现的各种情况，

递归的想法很自然，为什么呢？判断完当前字符，如果匹配，继续递归到下一个
字符，否则返回false

具体地，递归需要判断哪些情况
	对应位置上，
b.	str中的字符与pattern中的字符相等，
		b1. 并且都是字符串结束符，返回true
		b2. 否则，继续递归
c.	pattern中当前字符与str当前字符相等，并且pattern当前字符后面的字符是 '*'，
		进行下一步判断的时候，pattern有两种选择，
		c1.	str向后移动一位，pattern跳到*后的字符，相当于pattern当前字符出现0次
		c2.	str向后移动一位，pattern保持原位不动
		c3. str不动，pattern跳到*后的字符，
		上述三种情况都要继续递归（不能用str不动，pattern不动的情况，就陷入了死循环）
d.  pattern中当前字符与str当前字符不等，并且pattern当前字符后面的字符是 '*',
        str不动，pattern向后移动两位
            为什么不是 str向后移动两位，pattern不动呢，因为这样就相当于没有匹配str当前位，
                    肯定是不行的
d.	str中是字符 ，pattern中是 '.'，继续递归


写代码前要考虑好测试用例：
1.	str、pattern都为空，str、pattern有一个为空
2.	str、pattern都为空字符串，str、pattern有一个为空字符串
3.	str、pattern都不为空字符串，能匹配上/不能匹配上		
*/

bool matchCore(char *str, char *pattern);

bool match(char *str, char *pattern){
	if(str == NULL || pattern == NULL)
		return false;

	return matchCore(str, pattern);
}

bool matchCore(char *str, char *pattern){
	cout << "len(str): " << strlen(str) << endl;
	cout << "len(pattern): " << strlen(pattern) << endl;
    if(*str == '\0' && *pattern == '\0')
		return true;
    if(*str != '\0' && *pattern == '\0')
        return false;
    if(*(pattern+1) == '*'){
        if(*str == *pattern || (*str != '\0' && *pattern == '.'))
            return matchCore(str+1, pattern) ||
                    matchCore(str+1, pattern+2) ||
                    matchCore(str, pattern+2);
        else
            return matchCore(str, pattern+2);
    }
    if(*str == *pattern || (*str != '\0' && *pattern == '.'))
		return matchCore(str+1, pattern+1);

    return false;
}

int main(){
	char str[] = {'a','a','a'};
	//char pattern[] = {'a','b','*','a','c','*','a'};
	char pattern[] = {'a','.','a'};

	bool res = match(str, pattern);
	cout << "res: " << res << endl;
}
