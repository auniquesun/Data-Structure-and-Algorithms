#include<iostream>
#include<algorithm>
#include<string>

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
		for(int i=0; i<str.length(); i++){
			suffix[i] = &str[i];	//把str【i】的地址赋给 
			cout << suffix[i] << endl;
		}

		sort(suffix, suffix + str.length());

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
