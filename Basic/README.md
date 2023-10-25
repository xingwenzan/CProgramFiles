# 基础课目录

> 内容全部来自[`算法基础课`](https://www.acwing.com/activity/content/11/)

- [基础算法](BasicAlgorithms) &#x2002;
  包括排序、二分、高精度、前缀和与差分、双指针算法、位运算、离散化、区间合并等内容。
- [数据结构](DataStructure) &#x2002;
  包括单链表，双链表，栈，队列，单调栈，单调队列，KMP，Trie，并查集，堆，哈希表等内容。
    - [单链表](DataStructure/SingleList.c)
    - [`双链表`](https://www.acwing.com/activity/content/problem/content/864/) &#x2002; 太懒了，嫌麻烦没写
    - [栈](DataStructure/Stack)
        - [模拟栈](DataStructure/Stack/SimulationStack.c)
        - [栈的应用：表达式求值](DataStructure/Stack/ExpressionEvaluation.c)
    - [队列](DataStructure/Queue.c)
    - [单调栈](DataStructure/MonotonicStack.c)
    - [单调队列](DataStructure/MonotonicQueue.c)
    - [KMP字符串](DataStructure/KMP.c)
    - [Tire 树](DataStructure/Trie)
        - [Trie字符串统计](DataStructure/Trie/StringStatistics.c)
        - [最大异或对](DataStructure/Trie/MaximumXorPair.c)
    - [并查集](DataStructure/AndLookup)
        - [合并集合](DataStructure/AndLookup/MergeCollection.c)
        - [连通块中点的数量](DataStructure/AndLookup/ConnectedBlockPointNum.c)
        - [食物链](DataStructure/AndLookup/FoodChain.c)
    - [堆](DataStructure/Heap)
        - [堆排序](DataStructure/Heap/HeapSort.c)
        - [模拟堆](DataStructure/Heap/MockHeap.c)
    - [哈希表](DataStructure/Hash)
        - [模拟散列表](DataStructure/Hash/AnalogHash.c)
        - [字符串哈希](DataStructure/Hash/StringHash.c)
- [搜索与图论](SearchAndGraphTheory) &#x2002;
  包括DFS，BFS，树与图的深度优先遍历，树与图的广度优先遍历，拓扑排序，Dijkstra，bellman-ford，spfa，Floyd，Prim，Kruskal，染色法判定二分图，匈牙利算法等内容。
    - [DFS](SearchAndGraphTheory/DFS)
        - [排列数字](SearchAndGraphTheory/DFS/ArrangeNumbers.c)
        - [n-皇后问题](SearchAndGraphTheory/DFS/NQueens.c)
    - [BFS](SearchAndGraphTheory/BFS)
        - [走迷宫](SearchAndGraphTheory/BFS/MazeWalking.c)
        - [`八数码`](https://www.acwing.com/problem/content/847/) &#x2002; 太麻烦了，这个就不写了吧
    - [树与图的深度优先遍历](SearchAndGraphTheory/DFS/DFS.c)
    - [树与图的广度优先遍历](SearchAndGraphTheory/BFS/BFS.c)
    - [拓扑排序](SearchAndGraphTheory/TopologicalSort.c)
    - [Dijkstra](SearchAndGraphTheory/Dijkstra)
        - [Dijkstra求最短路 I](SearchAndGraphTheory/Dijkstra/DijkstraI.c)
        - [Dijkstra求最短路 II](SearchAndGraphTheory/Dijkstra/DijkstraII.c)
    - [bellman-ford](SearchAndGraphTheory/BellmanFord.c)
    - [spfa](SearchAndGraphTheory/SPFA)
        - [spfa求最短路](SearchAndGraphTheory/SPFA)
        - [spfa判断负环](SearchAndGraphTheory/SPFA/JudgmentNegativeLoop.c)
    - [Floyd](SearchAndGraphTheory/Floyd.c)
    - [Prim](SearchAndGraphTheory/Prim.c)
    - [Kruskal](SearchAndGraphTheory/Kruskal.c)
    - [染色法判定二分图](SearchAndGraphTheory/ColoringMethod.c)
    - [二分图的最大匹配](SearchAndGraphTheory/HungarianAlgorithm.c)
- [数学知识](MathematicalKnowledge) &#x2002; 包括质数，约数，欧拉函数，快速幂，扩展欧几里得算法，中国剩余定理，高斯消元，求组合数，容斥原理，博弈论等内容。
    - [质数](MathematicalKnowledge/PrimeNumbers)
        - [试除法判定质数](MathematicalKnowledge/PrimeNumbers/TrialDivision.c)
    - [约数](MathematicalKnowledge/Approximation)
        - [最大公约数](MathematicalKnowledge/Approximation/GreatestCommonDivisor.c)