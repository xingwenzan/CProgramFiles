cmake_minimum_required(VERSION 3.24)
project(AlgorithmC C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgorithmC main.c Basic/BasicAlgorithms/QuickSort/QuickSort.c Basic/BasicAlgorithms/QuickSort/QuickChoose.c Basic/BasicAlgorithms/MergeSort/MergeSort.c Basic/BasicAlgorithms/MergeSort/ReversePair.c Basic/BasicAlgorithms/Dichotomize/RangeOfNumbers.c Basic/BasicAlgorithms/Dichotomize/CubeRootOfNumber.c Basic/BasicAlgorithms/HighPrecision/Addition.c Basic/BasicAlgorithms/PrefixSumAndDifference/PrefixSum.c 学校作业/实验一/test1_1.c 学校作业/实验一/test1_2.c 学校作业/实验一/test1_3.c Basic/BasicAlgorithms/PrefixSumAndDifference/TruncateArray.c Basic/BasicAlgorithms/PrefixSumAndDifference/SumOfSubmatrices.c Basic/BasicAlgorithms/PrefixSumAndDifference/Difference.c Basic/BasicAlgorithms/PrefixSumAndDifference/ChangeArrayElements.c Basic/BasicAlgorithms/DoublePointer/LongestNonRepeatingSubsequence.c Basic/BasicAlgorithms/DoublePointer/ArrayElementsTargetSum.c Basic/BasicAlgorithms/DoublePointer/JudgmentSubsequence.c Basic/BasicAlgorithms/BitOperation.c Basic/BasicAlgorithms/Discretization.c Basic/BasicAlgorithms/IntervalMerge.c Basic/DataStructure/SingleList.c OtherSolutions/LeftChildRightBrother.c Basic/DataStructure/Stack/SimulationStack.c Basic/DataStructure/Stack/ExpressionEvaluation.c 学校作业/实验二/test2_1.c 学校作业/实验二/test2_3_1.c 学校作业/实验二/test2_3_2.c 学校作业/实验二/test2_3_3.c 学校作业/实验二/test2_2_1.c 学校作业/实验二/test2_2_2.c Basic/DataStructure/Queue.c Basic/DataStructure/MonotonicStack.c Basic/DataStructure/MonotonicQueue.c Basic/DataStructure/KMP.c
        Basic/DataStructure/Trie/StringStatistics.c
        Basic/DataStructure/Trie/MaximumXorPair.c
        学校作业/实验三/test_3_2.c
        学校作业/实验三/test_3_3_1.c
        Basic/MathematicalKnowledge/Approximation/GreatestCommonDivisor.c
        学校作业/实验三/test_3_3_2.c
        Basic/DataStructure/AndLookup/MergeCollection.c
        Basic/DataStructure/AndLookup/ConnectedBlockPointNum.c
        Basic/DataStructure/AndLookup/FoodChain.c
        学校作业/期末作业/Version1_0.c
        学校作业/期末作业/Version1_1.c
        Basic/DataStructure/Heap/HeapSort.c
        学校作业/期末作业/Version1_2.c
        学校作业/期末作业/Version1_3.c
        Basic/DataStructure/Heap/MockHeap.c
        Basic/DataStructure/Hash/AnalogHash.c
        Basic/DataStructure/Hash/StringHash.c Basic/SearchAndGraphTheory/DFS/ArrangeNumbers.c Basic/SearchAndGraphTheory/DFS/NQueens.c Basic/SearchAndGraphTheory/BFS/MazeWalking.c Basic/SearchAndGraphTheory/DFS/DFS.c Basic/SearchAndGraphTheory/BFS/BFS.c Basic/SearchAndGraphTheory/TopologicalSort.c Basic/SearchAndGraphTheory/Dijkstra/DijkstraI.c Basic/SearchAndGraphTheory/Dijkstra/DijkstraII.c
        Basic/SearchAndGraphTheory/BellmanFord.c
        Basic/SearchAndGraphTheory/SPFA/FindShortestPath.c
        Basic/SearchAndGraphTheory/SPFA/JudgmentNegativeLoop.c)

link_libraries(libeasyx.a)

