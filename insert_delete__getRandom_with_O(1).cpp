#include<iostream>
#include <set>
#include <ctime> // 产生随机数用作seed，因为每次执行的时间不同，所以传入srand的seed就不同，所以后面调用rand()产生的数和上次不同
#include <cstdlib> // 产生随机数用到

using namespace std;

/*
	problem：
	设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。

	insert(val)：当元素 val 不存在时，向集合中插入该项。
	remove(val)：元素 val 存在时，从集合中移除该项。
	getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。
	示例 :

	// 初始化一个空的集合。
	RandomizedSet randomSet = new RandomizedSet();

	// 向集合中插入 1 。返回 true 表示 1 被成功地插入。
	randomSet.insert(1);

	// 返回 false ，表示集合中不存在 2 。
	randomSet.remove(2);

	// 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
	randomSet.insert(2);

	// getRandom 应随机返回 1 或 2 。
	randomSet.getRandom();

	// 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
	randomSet.remove(1);

	// 2 已在集合中，所以返回 false 。
	randomSet.insert(2);

	// 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
	randomSet.getRandom();

    idea：
    这道题是一个设计题目，要求 insert，remove，getRandom操作的时间复杂度为O(1)
    （1）当然可以自己设计一个数据结构，用hash加上其他方法能满足题目要求
    （insert，getRandom操作，很容易满足；remove操作需要直接定位到元素位置，才能满足O(1)）
    （2）还有一个想法是利用 c++ 提供的标准库里的数据结构，如 stack,queue,set,list,vector等
        这些内置类库中的数据结构，插入、删除、访问都很高效，直接利用这些也能解决问题，
        我所采用的方法就是利用这些内置类库提供的数据结构
*/

class RandomizedSet {
private:
    set<int> s;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(unsigned time(0));    // 在实例初始化时调用，srand()传入的参数是以当前执行时间为准的，
                                    // 保证了rand()产生的随机数，每执行一次都不一样，满足题目要求，
                                    // 这一点很重要
        cout << "执行了RandomizedSet" << endl;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        cout << "执行了insert" << endl;
        if(s.find(val) == s.end()){ // 集合s中不存在val, 才执行插入操作
            s.insert(val);
            cout << "insert true" << endl;
            return true;
        }
        else{
            cout << "insert false" << endl;
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        cout << "执行了remove" << endl;
        if(s.find(val) != s.end()){ // 集合s中存在val, 才执行删除操作
            s.erase(val);
            cout << "remove true" << endl;
            return true;
        }
        else{
            cout << "remove false" << endl;
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        cout << "执行了getRandom" << endl;
        if(s.size() > 0){
            int i = rand()%s.size();
            
            set<int>::iterator it = s.begin();  // 要先给it赋初值！！！这么低级的错误竟然没看出来
            advance(it, i);
            
        int num = *it;
            cout << "getRandom true" << endl;

            return num;
        }
        else{
            int rand;
            cout << "getRandom false" << endl;
            return rand;
        }
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(int argc, char const *argv[])
{
    /* code */
	RandomizedSet *obj = new RandomizedSet();
	bool param_1 = obj->insert(1);
	bool param_2 = obj->remove(2);
	bool param_3 = obj->insert(2);
	int param_4 = obj->getRandom();
	cout << "param_4: " << param_4 << endl;
	bool param_5 = obj->remove(1);
	bool param_6 = obj->insert(2);
	int param_7 = obj->getRandom();
	cout << "param_7: " << param_7 << endl;

	return 0;
}
