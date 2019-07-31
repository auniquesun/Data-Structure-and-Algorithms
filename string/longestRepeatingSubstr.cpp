#include<iostream>
#include<algorithm>
#include<string>

/*
   这个题，就是腾讯春招提前批的题，和 最长公共子串 不一样的地方是，
   这个题需要在 字符串内部 找出这样的子串
   例子： “banana” 这个词，“an”是重复子串，“ana”是重复子串，“a” “n”是重复子串，
    但是最长的显然是 “ana”
   */
using namespace std;
int getNumOfCommonChar(char *s1, char *s2){
    int num = 0;
    while(s1 != NULL && s2 != NULL && *s1 == *s2){
        num++;
        s1++;
        s2++;
    }
    return num;
}

string LRS(string str){
	if(str.length() > 0){
		char **suffix = new char* [str.length()];	//suffix是指向指针数组的指针
                                                    //建立这个二维数组很关键
		for(int i=0; i<str.length(); i++){
			suffix[i] = &str[i];	//把str【i】的地址赋给
			cout << suffix[i] << endl;
		}

		sort(suffix, suffix + str.length());    // 排序操作很关键

		int max_length = 0, max_index = 0;
		for(int i=0; i<str.length()-1; i++){
			for(int j=i+1; j<str.length(); j++){
				int num_common_char = getNumOfCommonChar(suffix[i], suffix[j]);
				if(num_common_char > max_length){
					max_length = num_common_char;
					max_index = i;
				}
			}
		}
        cout << "max_length: " << max_length << endl;
        if(max_length > 0){
            char *result = new char [max_length];
            for(int i=0; i<max_length; i++)
                result[i] = suffix[max_index][i];   //这种赋值方式更容易理解, 第max_index个字符串的前max_length个元素
            return result;
        }

		return "";
	}
	else return "";
}

int main(int argc, char const *argv[])
{
	/* code */
	string str;
    cout << "input a string: ";
	cin >> str;
	cout << "longest repeating substr of " << str << " is: " << LRS(str) << endl;
	return 0;
}
