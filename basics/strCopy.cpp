#include "public.h"

/*
1. 首先说明 strcpy 的头文件是 <cstring>
2. strcpy拷贝字符串时，会在字符串末尾加一个'\0'，一同拷贝到目标数组
3. string作为第二个参数，要用.c_str()转化成字符数组首地址
4. printf()是个打印备选项
*/

int main(){

    string s1 = "i love you";
    char s2 [11];
    strcpy(s2, s1.c_str());
    for(int i=0; i<11; i++)
        if(s2[i]!='\0')
        cout << s2[i] << endl;

    char s3[] = "something that can be difficult is neccessary.";
    char s4[30];
    strcpy(s4, s3);
    printf("%s\n", s4);
}
