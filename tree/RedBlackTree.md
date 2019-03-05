# What is red black tree?
 红黑树是一颗平衡的二叉搜索树，每个节点满足下列性质：<br/>
1. 节点颜色只能是红色或黑色中的一种<br/>
2. 根节点是黑色<br/>
3. 对于红色节点来说，它不能有红色的父节点或子节点<br/>
4. 从树中任一特定节点到所有叶节点的路径上，黑色节点的个数相同<br/>
5. 从树根到最远叶节点的路径长度不超过树根到最近叶节点路径长度的两倍<br/>

# Why red black tree?
从红黑树中搜索、插入、删除、寻找最小值/最大值，时间复杂度为O(logn)<br/>
# Comparision with AVL tree
1. AVL tree也是一颗二叉搜索树，每个节点存有该节点子树的平衡因子，对平衡的限制非常严，所以查找一般在O(logn)时间完成，相比red-black tree更快，red-black tree的平衡限制没有这么严<br/>
2. AVL tree 比 red black tree 更平衡，但是做insert或者deletion的时候，rotation通常更多<br/>
3. AVL trees provide faster lookups than Red Black Trees because they are more strictly balanced.<br/>
4. Red Black Trees provide faster insertion and removal operations than AVL trees as fewer rotations are done due to relatively relaxed balancing.<br/>
5. AVL trees store balance factors or heights with each node, thus requires storage for an integer per node whereas Red Black Tree requires only 1 bit of information per node.<br/>
6. Red Black Trees are used in most of the language libraries like map, multimap, multiset in C++ whereas AVL trees are used in databases where faster retrievals are required.<br/>
So if your application involves many frequent insertions and deletions, then Red Black trees should be preferred.<br/>
And if the insertions and deletions are less frequent and search is a more frequent operation, then AVL tree should be preferred over Red-Black Tree.<br/>
# How does a red black tree ensure balance?
