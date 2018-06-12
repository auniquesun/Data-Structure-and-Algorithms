#include <iostream>
#include <string>
using namespace std;

// ideas' Reference: https://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/

// ================== idea one: recusion ==================
// 求字符串source 到 字符串target的编辑距离，思路是：
// ①从左到右 或者 从右到左扫描两个字符串
// ②
// 	a.如果扫描的两个字符相同，那么不对source进行 插入、删除、替换操作
// 	b.如果扫描的两个字符不相同，考虑对source进行 插入、删除、替换操作，递归求解操作次数最少的距离
// 		b1 插入 len_source = len_source,len_target = len_target - 1
// 		b2 替换 len_source = len_source - 1,len_target = len_target - 1
// 		b3 删除 len_source = len_source - 1,len_target = len_target
//		注：这里的插入、删除、替换操作，只在source上进行，不动target

int min(int x,int y,int z){// 求三个数中的最小值
	//先找出x，y中的最小值，再和另一个值比较
	return ((x<y?x:y)<z)?(x<y?x:y):z;
}


int recusion_EditDistance(string source,string target,int len_source,int len_target){
	if(len_source == 0)
		return len_target;

	if(len_target == 0)
		return len_source;

	if(source[len_source - 1] == target[len_target - 1])
		return recusion_EditDistance(source,target,len_source - 1,len_target - 1);

	if(source[len_source - 1] != target[len_target - 1])
					   // b1 INSERT:
					   // 在source插入一个字符，与target最后一个字符相同，
					   // 然后再从source和target把这个相同的字符删掉，
					   // 所以source的长度仍为len_source，target的长度减少1
		return 1 + min(recusion_EditDistance(source,target,len_source,len_target - 1),
					   // b2 REPLACE:
					   // 在source替换一个字符，替换后与target最后一个字符相同，
					   // 然后再从source和target把这个相同的字符删掉，
					   // 所以source的长度减少1，target的长度减少1
					   recusion_EditDistance(source,target,len_source - 1,len_target - 1),
					   // b3 DELETE:
					   // 在source删除最后一个字符，
					   // 所以source的长度减少1，target的长度仍为len_source
					   recusion_EditDistance(source,target,len_source - 1,len_target)	
					   );	
}


// ================== idea two: dynamic programming ==================
// We can see that many subproblems are solved, again and again, 
// for example, eD(2,2) is called three times. 
// Since same subproblems are called again, 
// this problem has Overlapping Subprolems property. 
// So Edit Distance problem has both properties of a dynamic programming problem. 
// Like other typical Dynamic Programming(DP) problems, 
// recomputations of same subproblems can be avoided 
// by constructing a temporary array that stores results of subproblems.


int dp_EditDistance(string source,string target,int len_source,int len_target){
	int dp[len_source + 1][len_target + 1];

	int i,j;

	for(i=0;i<=len_source;i++){
		for(j=0;j<=len_target;j++){
			// If first string is empty, only option is to
            // insert all characters of second string
			if(i == 0)
				dp[i][j] = j;

			// If second string is empty, only option is to
            // remove all characters of second string
			else if(j == 0)
				dp[i][j] = i;

			// If last characters are same, ignore last char
            // and recur for remaining string
			else if(source[i-1] == target[j-1])
				dp[i][j] = dp[i-1][j-1];

			else 				// b1 INSERT
				dp[i][j] = 1 + min(dp[i][j-1],
								// b2 REPLACE
							   dp[i-1][j-1],
							    // b3 DELETE
							   dp[i-1][j]
					          );
		}
	}

	return dp[len_source][len_target];
}


int main(){
	string source,target;
	cout<<"input source and target respectively: "<<endl;
	cin>>source>>target;

	//idea one
	// cout<<"the distance between "<<source<<" and "<<target<<" is "<<recusion_EditDistance(source,target,source.length(),target.length())<<endl;

	//idea two
	cout<<"the distance between "<<source<<" and "<<target<<" is "<<dp_EditDistance(source,target,source.length(),target.length())<<endl;
}









