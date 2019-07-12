/*
problem:
    给定一个数字，比如321,
    要求把这个数字进行翻译，翻译的规则如下：
    0->a, 1->b, 2->c, ..., 25->z
    求给定的数字能有多少种翻译方法？
    拿321来说，可以翻译成 dcb, dv，所以有两种翻译方法

idea:
    动态规划的思想吧, 这个题很巧妙，是从数字的最后一位往前推的
    和之前从前往后推的做法不一样，单本质的思想是一样的
*/

int countOfNumberTranslations(int number){
    if(number < 0)
        return 0;

    string str = to_string(number);

    int count;
    int counts[str.length()];

    for(int i=str.length()-1; i>=0; i--){
        count = 0;
        if(i<str.length()-1)
            count = counts[i+1];
        else
            count = 1;

        if(i<str.length()-1){
            int digit = str[i] - '0';
            int digit_next = str[i+1] - '0';
            if(10*digit + digit_next >= 10 && 10*digit + digit_next <=25){
                if(i<str.length()-2)
                    count += counts[i+2];
                else
                    count += 1;
            }
            counts[i] = count;
        }
    }
    count = counts[0];
    delete [] counts;
    return count;
}
