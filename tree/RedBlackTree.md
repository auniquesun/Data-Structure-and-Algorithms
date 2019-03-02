# What is red black tree?
1. 红黑树是一颗平衡的二叉搜索树，每个节点满足下列性质：<br/>
<ol>
节点颜色只能是红色或黑色中的一种<br/>
根节点是黑色<br/>
对于红色节点来说，它不能有红色的父节点或子节点<br/>
从树中任一特定节点到所有叶节点的路径上，黑色节点的个数相同<br/>
</ol>
# Why red black tree?
从红黑树中搜索、插入、删除、寻找最小值/最大值，时间复杂度为O(logn)<br/>
# Comparision with AVL tree
AVL tree 比 red black tree 更平衡，但是做insert或者deletion的时候，rotation通常更多<br/>
<li>
So if your application involves many frequent insertions and deletions, then Red Black trees should be preferred.<br/>
And if the insertions and deletions are less frequent and search is a more frequent operation, then AVL tree should be preferred over Red-Black Tree.<br/>
<li/>
# How does a red black tree ensure balance?
