/*
problem:
给定一个随机数生成器 rand3()，它能等概率生成[1,3]之间的整数，
利用 rand3(), 求解随机数生成器 rand7(), 等概率生成[1,3]之间的整数

注： 等概率很重要，如果不等概率，rand3() + rand3() + rand3() - 2 就是一种解法

idea:
解法一
7比3大，生成两次rand3，构建如下一个 vals数组，
如果vals[i][j]仍等于0，抛弃；否则返回
因为 vals 中 1,2,3,4,5,6,7 每个只出现一次，
而且rand3生成的 1,2,3 也是等概率，所以保证生成的[1,7]间的整数也等概率

解法二
rejection sampling 方法，
即生成[1, 9]的随机数，如果数的范围不在[1, 7]内，则重新取样
*/

int rand7()
{
    int vals[3][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 0, 0 },
    };

    // 解法一
    int result = 0;
    while (result == 0)
    {
        int i = rand3();
        int j = rand3();
        result = vals[i-1][j-1];
    }

    // 解法二
    int result = 0;
    do {
        result = 3 * (rand3() - 1) + rand3();
    } while (result > 7);
    
    // 扩展到一般情况： rand_m() 生成 rand_t()
    do {
        result = m * (rand_m() - 1) + rand_m();
    } while (result > t);
    
    return result%7 + 1;
}
