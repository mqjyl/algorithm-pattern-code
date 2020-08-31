cmake_minimum_required(VERSION 3.14)
project(algorithm_pattern_code)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithm_pattern_code main.cpp src/ListHandler.cpp ListHandler.h Nodes.h src/BinaryTree.cpp BinaryTree.h src/SortTool.cpp SortTool.h src/BinarySearchTree.cpp BinarySearchTree.h src/Recursive.cpp Recursive.h src/DivideConquer.cpp DivideConquer.h src/DynamicProgramming.cpp DynamicProgramming.h src/BitOperations.cpp BitOperations.h src/HashTable.cpp HashTable.h src/StringHandler.cpp StringHandler.h src/SlidingWindow.cpp SlidingWindow.h src/BackTracking.cpp BackTracking.h src/OtherExecs.cpp OtherExecs.h src/GraphHandler.cpp GraphHandler.h src/BFS_DFS.cpp BFS_DFS.h src/StackAndQueue.cpp StackAndQueue.h)