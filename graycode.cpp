/*
problem: 格雷码
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。

给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。

示例 1:

输入: 2
输出: [0,1,3,2]
解释:
00 - 0
01 - 1
11 - 3
10 - 2

对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。

00 - 0
10 - 2
11 - 3
01 - 1
示例 2:

输入: 0
输出: [0]
解释: 我们定义格雷编码序列必须以 0 开头。
     给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
     因此，当 n = 0 时，其格雷编码序列为 [0]。

idea: 
L2 是 L1 的逆序，这个思路很重要，
这意味着从{0,1}开始迭代，插入prefix后，相邻的元素只有一位之差
n-bit Gray Codes can be generated from list of (n-1)-bit Gray codes using following steps.
1) Let the list of (n-1)-bit Gray codes be L1. Create another list L2 which is reverse of L1.
2) Modify the list L1 by prefixing a ‘0’ in all codes of L1.
3) Modify the list L2 by prefixing a ‘1’ in all codes of L2.
4) Concatenate L1 and L2. The concatenated list is required list of n-bit Gray codes.

For example, following are steps for generating the 3-bit Gray code list from the list of 2-bit Gray code list.
L1 = {00, 01, 11, 10} (List of 2-bit Gray Codes)
L2 = {10, 11, 01, 00} (Reverse of L1)
Prefix all entries of L1 with ‘0’, L1 becomes {000, 001, 011, 010}
Prefix all entries of L2 with ‘1’, L2 becomes {110, 111, 101, 100}
Concatenate L1 and L2, we get {000, 001, 011, 010, 110, 111, 101, 100}
*/

class Solution {
public:
	int str2int(string str){
		int sum = 0;
		for(int i=0;i<str.length();i++){
			sum += str[i] * pow(2, str.length() - 1 - i);
		}

		return sum;
	}
    vector<int> grayCode(int n) {
		vector<int> res;	//存储最终返回的整数结果
		if(n==0){
			res.push_back(0);
			return res;
		}

		vector<string> bi_res;	//存储每次迭代的二进制字符串
		bi_res.push_back("0");	//初始化
		bi_res.push_back("1");

		int i,j;

		for(i=2; i < (1<<n); i = (i<<1)){	//i每次左移一位，i要小于(数字1左移n位,即1后面n个0)
			for(j=i-1;j>=0;j--){
				bi_res.push_back(bi_res[j]);
			}

			for(j=0;j<i;j++)	//在bi_res前一半数字前面加0
				bi_res[j] = "0" + bi_res[j];

			for(j=i;j<2*i;j++)	//在bi_res后一半数字前面加1
				bi_res[j] = "1" + bi_res[j];				
		}

		for(int i=0; i<bi_res.size(); i++){
			int num = str2int(bi_res[i]);
			res.push_back(num);
		}
    }
};