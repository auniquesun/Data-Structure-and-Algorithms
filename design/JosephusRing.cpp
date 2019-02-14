#include<list>
#include<iostream>
using namespace std;

/*
problem: 给定n，m；求 Josephus Ring 中最后一个数
		n指定了0,1,...,n-2,n-1这n个数，按顺序排列，组成一个环
		m指定了从当前数起，删除环中第m个数，不断循环，
		求最后剩下的数
idea：
	约瑟夫环问题最重要就是搞清楚数字删除过程，	剩下就很简单——
	a. 从0开始，往后走m-1步，找到要删除的数字，删掉
	b. 删除完一个数，指针自动挪到下一个元素上面（有下一个元素的话）
	c. 从这个数开始，再往后走m-1步，就到达了下一个要删除的数，删掉
	重复b、c，直到只剩一个数，返回

	用链表模拟这个环（其实向量也完全可以）
	需要记录当前要删除的节点cur，要删除节点的下一个节点next
*/
int JosephusRing(int n, int m){
	if(n<1 || m < 1){
		cout << "value n/m error" << endl;
		return -1;
	}
	list<int> ring;
	for(int i=0; i<n; i++)
		ring.push_back(i);

    cout << "ring: ";
	for(list<int>::iterator it=ring.begin(); it!=ring.end(); it++)
		cout << *it << " ";
    cout << endl;

	list<int>::iterator current = ring.begin();
	while(ring.size()>1){
		for(int i=0; i<m-1; i++){// 这么低级的错误，for循环中的语句要用大括号括起来，
                                    // 之前忘加大括号了
			current++;
			if(current == ring.end())
				current = ring.begin();
        }
        // current要先++
		list<int>::iterator next = ++current;
        if(next == ring.end())
            next = ring.begin();
        --current;
        cout << "to be deleted: " << *current << endl;
		ring.erase(current);
		current = next;
	}
	return *current;
}

int AdvancedJosephusRing(int n, int m){
	if(n<1 || m < 1){
		cout << "value n/m error" << endl;
		return -1;
	}

    int last = 0;
    for(int i=2; i<=n; i++){
        last = (last+m)%i;
    }
    
    return last;
}

int main(int argc, char const *argv[])
{
	/* code */
	int n,m;
	cout << "input n,m respectively: ";
    cin >> n >> m;
	cout << "last element of JosephusRing: " << JosephusRing(n, m) << endl;
	cout << "last element of AdvancedJosephusRing: " << AdvancedJosephusRing(n, m) << endl;
	return 0;
}
