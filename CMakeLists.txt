cmake_minimum_required(VERSION 3.24)
project(AlgorithmC C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgorithmC main.c BasicAlgorithms/QuickSort/QuickSort.c BasicAlgorithms/QuickSort/QuickChoose.c BasicAlgorithms/MergeSort/MergeSort.c BasicAlgorithms/MergeSort/ReversePair.c BasicAlgorithms/Dichotomize/RangeOfNumbers.c BasicAlgorithms/Dichotomize/CubeRootOfNumber.c BasicAlgorithms/HighPrecision/Addition.c BasicAlgorithms/PrefixSumAndDifference/PrefixSum.c 学校作业/实验一/test1_1.c 学校作业/实验一/test1_2.c 学校作业/实验一/test1_3.c)
