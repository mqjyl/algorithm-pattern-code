cmake_minimum_required(VERSION 3.14)
project(algorithm_pattern_code)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithm_pattern_code main.cpp src/ListHandler.cpp include/ListHandler.h include/Nodes.h src/BinaryTree.cpp include/BinaryTree.h src/SortTool.cpp include/SortTool.h src/BinarySearchTree.cpp include/BinarySearchTree.h src/Recursive.cpp include/Recursive.h src/DivideConquer.cpp include/DivideConquer.h src/DynamicProgramming.cpp include/DynamicProgramming.h src/BitOperations.cpp include/BitOperations.h src/HashTable.cpp include/HashTable.h src/StringHandler.cpp include/StringHandler.h src/SlidingWindow.cpp include/SlidingWindow.h src/BackTracking.cpp include/BackTracking.h src/OtherExecs.cpp include/OtherExecs.h src/GraphHandler.cpp include/GraphHandler.h src/BFS_DFS.cpp include/BFS_DFS.h src/StackAndQueue.cpp include/StackAndQueue.h)