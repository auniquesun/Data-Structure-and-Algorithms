#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

// ================ problem ===============
// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

// 示例:

// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// 说明：
// 所有输入均为小写字母。
// 不考虑答案输出的顺序。

// ==================== idea ==================
// Let us understand the steps with following input Sequence of Words:

// "cat", "dog", "tac", "god", "act"
// 1) Create two auxiliary arrays index[] and words[]. Copy all given words to words[] and store the original indexes in index[]

// index[]:  0   1   2   3   4
// words[]: cat dog tac god act
// 2) Sort individual words in words[]. Index array doesn’t change.

// index[]:   0    1    2    3    4
// words[]:  act  dgo  act  dgo  act
// 3) Sort the words array. Compare individual words using strcmp() to sort

// index:     0    2    4    1    3
// words[]:  act  act  act  dgo  dgo
// 4) All anagrams come together. But words are changed in words array. To print the original words, take index from the index array and use it in the original array. We get

// "cat tac act dog god"

struct gram_node
{
	int index;
	string str;
};

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > result;

    vector<string> grams;		// 存放result的每一行值

    int n = strs.size();

    //cout << n << "###############" << endl;

    int i,j,k;

    gram_node *gram_nodes = new gram_node[n];

    for(i=0;i<n;i++){

        gram_nodes[i].index = i;

        gram_nodes[i].str = strs[i];

    }

    for(i=0;i<n;i++){

        int gram_len = gram_nodes[i].str.length();

        char *gram = new char [gram_len + 1];         

        //char gram[] = new char [gram_len + 1];

        strcpy(gram,gram_nodes[i].str.c_str());		// 把string转成char*
        gram[gram_len] = '\0';

        //char gram[] = gram_nodes[i].str;
        //int gram_len = gram_nodes[i].str.length();

        sort(gram,gram + gram_len);	// 针对每个词内部字母排序

        gram_nodes[i].str = gram;	// 排序后的结果重新赋值给 gram_nodes[i].str

    }

    for(i=0;i<n-1;i++){		// 重小到大排序 gram_nodes 数组

        k = i;	// 默认 gram_nodes[i] 为该位置最小的

        for(j=i+1;j<n;j++){

            if(gram_nodes[k].str > gram_nodes[j].str)

                k=j;

        }

        if(k!=i){
            gram_node tmp_gram_node;
            tmp_gram_node = gram_nodes[i];
            gram_nodes[i] = gram_nodes[k];
            gram_nodes[k] = tmp_gram_node;
        }

    }

    for(i=0,j=i+1;i<n-1&&j<n;i++,j=i+1){

        if(gram_nodes[i].str == gram_nodes[j].str){

            grams.push_back(strs[gram_nodes[i].index]);

        }else{

            grams.push_back(strs[gram_nodes[i].index]);

            result.push_back(grams);

            grams.clear();		// 存储完每一个行值，及时清空grams

        }

    }

    grams.push_back(strs[gram_nodes[--j].index]);   // 退出上面的for循环时，j值为n，这里需要先减一

    result.push_back(grams);

//         for(i=0;i<result.size();i++){

//             for(j=0;j<result[i].size();j++){

//                 cout<<result[i][j]<<" ";

//             }

//             cout<<endl;

//         }

    return result;
}

int main()
{

	string arr[] = {"eat", "tea", "tan", "ate", "nat", "bat"};

	int n = sizeof(arr)/sizeof(arr[0]);

	vector<string> strs(arr,arr+n);

	/* code */

	return 0;
}