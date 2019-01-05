/*
problem: 把一个字符串中的空格替换为 '%20' 

先考虑测试用例：
1. 空字符串，或者干脆传过来一个 空指针
2. 只有一个空格，或者多个连续空格
3. 有字符有空格
*/

void replaceBlankChar(char str[], int length){
    if(length == 0 || str == NULL)
        return;

    
    int num_blank = 0;
    int originLength = 1;   // 至少有一个'\0'
    for(int i=0; str[i]!='\0'; i++){
        if(str[i] == ' ')
            num_blank++;
        originLength++;
    }

    int newLength = originLength + 2*num_blank;
    if(newLength > length)
        return;

    int origin_pos = originLength - 1;
    int new_pos = newLength - 1;
    while(newLength>origin_pos && new_pos>0 && origin_pos>0){
        if(str[origin_pos] == ' '){
            str[new_pos--] = '0';
            str[new_pos--] = '2';
            str[new_pos--] = '%';
        }
        else{
            str[new_pos--] = str[origin_pos];
        }
        origin_pos--;
    }
}