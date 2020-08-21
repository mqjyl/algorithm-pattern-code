//
// Created by mqjyl on 2020/8/12.
//

#ifndef ALGORITHM_PATTERN_CODE_GRAPHHANDLER_H
#define ALGORITHM_PATTERN_CODE_GRAPHHANDLER_H
#include <vector>
#include "Nodes.h"

struct Edge{
    int st;
    int ed;
    int cost;
    Edge(int s, int e, int c) : st(s), ed(e), cost(c) {}
};

class GraphHandler {
public:
    // 133. Clone Graph
    Node* cloneGraph(Node* node);
    // 最短路径长度 Dijkstra
    void Dijkstra(int N, int S, std::vector<int>& dst, std::vector<std::vector<int>>& graph);
    // 记录最短路径
    void Dijkstra(int N, int S, std::vector<int>& dst, std::vector<int>& pre, std::vector<std::vector<int>>& graph);

    // 最小生成树 Prim
    int Prim(int N, std::vector<int>& dst, std::vector<std::vector<int>>& graph);
    // 最小生成树 Prim 记录路径
    int Prim(int N, std::vector<int>& dst, std::vector<int>& path, std::vector<std::vector<int>>& graph);

    // 最小生成树 Kruscal
    int Kruscal(std::vector<int>& trees, std::vector<Edge>& graph);
};


void testDijkstra();

void testPrim();

void testKruscal();


#endif //ALGORITHM_PATTERN_CODE_GRAPHHANDLER_H
