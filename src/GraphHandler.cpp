//
// Created by mqjyl on 2020/8/12.
//
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include "../include/GraphHandler.h"

using namespace std;

/**
 * 基本问题
 * */
const int MAX_LEN = 100001;

// 最短路径长度 Dijkstra
void GraphHandler::Dijkstra(int N, int S, vector<int>& dst, vector<vector<int>>& graph){
    vector<bool> book(N + 1, false);
    book[S] = true;
    for(int i = 1; i <= N; ++i)
        dst[i] = graph[S][i];
    dst[S] = 0;
    // 迭代 N - 1 次
    for(int i = 1; i < N ; ++i){
        int u = S;
        int tmp = MAX_LEN;
        // 找 u
        for(int j = 1; j <= N; ++j){
            if(!book[j] && tmp > dst[j]){
                tmp = dst[u = j];
            }
        }
        if(tmp == MAX_LEN)
            break;
        // 松弛边
        book[u] = true;
        for(int j = 1; j <= N; ++j){
            if(!book[j] && graph[u][j] != MAX_LEN){
                int d = dst[u] + graph[u][j];
                if(d < dst[j])
                    dst[j] = d;
            }
        }
    }
}

// 记录最短路径
void GraphHandler::Dijkstra(int N, int S, std::vector<int>& dst, std::vector<int>& pre, std::vector<std::vector<int>>& graph){
    vector<bool> book(N + 1, false);
    book[S] = true;
    for(int i = 1; i <= N; ++i)
    {
        dst[i] = graph[S][i];
        if(dst[i] != MAX_LEN)
            pre[i] = S;
        else
            pre[i] = 0;
    }

    dst[S] = 0;
    // 迭代 N - 1 次
    for(int i = 1; i < N ; ++i){
        int u = S;
        int tmp = MAX_LEN;
        // 找 u
        for(int j = 1; j <= N; ++j){
            if(!book[j] && tmp > dst[j]){
                tmp = dst[u = j];
            }
        }
        if(tmp == MAX_LEN)
            break;
        // 松弛边
        book[u] = true;
        for(int j = 1; j <= N; ++j){
            if(!book[j] && graph[u][j] != MAX_LEN){
                int d = dst[u] + graph[u][j];
                if(d < dst[j]){
                    dst[j] = d;
                    pre[j] = u;
                }
            }
        }
    }
}

void printPath(std::vector<int>& pre, int S, int T){
    int tmp = T;
    vector<int> path;
    while(tmp != S){
        path.push_back(tmp);
        tmp = pre[T];
        T = tmp;
    }
    path.push_back(S);
    for (int i = path.size() - 1; i >= 0; --i)
    {
        cout << path[i] << "->";
    }
    cout << endl;
}

void testDijkstra(){
    int N = 0, M = 0, S = 0, T = 0;
    GraphHandler graphHandler;
    while(cin >> N >> M >> S >> T){
        vector<int> dst(N + 1, MAX_LEN);
        vector<vector<int>> graph(N + 1, vector<int>(N + 1, MAX_LEN));
        int u, v, len;
        while(M-- > 0){
            cin >> u >> v >> len;
            if(len < graph[u][v]){
                graph[u][v] = graph[v][u] = len;
            }
        }
        vector<int> pre(N + 1);
        graphHandler.Dijkstra(N, S, dst, pre, graph);
        printPath(pre, S, T);
        cout << dst[T] << endl;
    }
}

// 最小生成树 Prim
int GraphHandler::Prim(int N, std::vector<int>& dst, std::vector<std::vector<int>>& graph){
    vector<bool> visited(N + 1, false);
    visited[1] = true;
    for(int i = 1; i <= N; ++i) {
        dst[i] = graph[1][i];
    }
    int result = 0;
    for(int i = 1; i < N; ++i){
        int tmp = MAX_LEN;
        int u = 1;
        for(int j = 1; j <= N; ++j){
            if(!visited[j] && tmp > dst[j]){
                tmp = dst[u = j];
            }
        }
        if(tmp == MAX_LEN)
            break;
        visited[u] = true;
        result += tmp;
        for(int j = 1; j <= N; ++j){
            if(!visited[j] && dst[j] > graph[u][j]){
                dst[j] = graph[u][j];
            }
        }
    }
    return result;
}

// 最小生成树 Prim 记录路径
int GraphHandler::Prim(int N, std::vector<int>& dst, std::vector<int>& pre, std::vector<std::vector<int>>& graph){
    vector<bool> visited(N + 1, false);
    visited[1] = true;
    for(int i = 1; i <= N; ++i) {
        dst[i] = graph[1][i];
        if(dst[i] != MAX_LEN)
            pre[i] = 1;
        else
            pre[i] = 0;
    }
    int result = 0;
    for(int i = 1; i < N; ++i){
        int tmp = MAX_LEN;
        int u = 1;
        for(int j = 1; j <= N; ++j){
            if(!visited[j] && tmp > dst[j]){
                tmp = dst[u = j];
            }
        }
        if(tmp == MAX_LEN)
            break;
        visited[u] = true;
        result += tmp;
        for(int j = 1; j <= N; ++j){
            if(!visited[j] && dst[j] > graph[u][j]){
                dst[j] = graph[u][j];
                pre[j] = u;
            }
        }
    }
    return result;
}

void testPrim(){
    int N = 0;
    cin >> N;
    int val = 0;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, MAX_LEN));
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            cin >> val;
            graph[i][j] = val;
        }
    }
    vector<int> dst(N + 1, MAX_LEN);
    vector<int> pre(N + 1);
    GraphHandler graphHandler;
    cout << graphHandler.Prim(N, dst, pre, graph);
    for(int i = 2; i <= N; ++i){
        cout << pre[i] << "->" << i << endl;
    }
}

//int Find(std::vector<int>& pre, int x){
//    return x == pre[x] ? x : pre[x] = Find(pre, pre[x]);
//}
//
//void Union(std::vector<int>& pre, int x,int y){
//    pre[Find(pre, x)] = Find(pre, y);
//}

// 最小生成树 Kruscal
int GraphHandler::Kruscal(std::vector<int>& trees, std::vector<Edge>& graph){
    int result = 0;
    // C++ 14
    auto recursiveFunc = std::make_shared<std::unique_ptr< std::function<int(int)> >>();
    *recursiveFunc = std::make_unique<std::function<int(int)>>(
        [=, &trees] (int a){
            return a == trees[a] ? a : (trees[a] = (**recursiveFunc)(trees[a]));
        }
    );
    // C++ 11
//    auto recursiveFunc = std::shared_ptr<std::unique_ptr< std::function<int(int)> >>(new std::unique_ptr< std::function<int(int)> >());
//    *recursiveFunc = std::unique_ptr<std::function<int(int)>>( new std::function<int(int)>(
//        [=, &trees] (int a){
//            return a == trees[a] ? a : (trees[a] = (**recursiveFunc)(trees[a]));
//        }
//    ));
    for(auto edge : graph){
        if((**recursiveFunc)(edge.st) != (**recursiveFunc)(edge.ed)){
            result += edge.cost;
            trees[(**recursiveFunc)(edge.st)] = (**recursiveFunc)(edge.ed);
        }
    }
    return result;
}

//int GraphHandler::Kruscal(std::vector<int>& trees, std::vector<Edge>& graph){
//    int result = 0;
//    for(auto edge : graph){
//        if(Find(trees, edge.st) != Find(trees, edge.ed)){
//            result += edge.cost;
//            Union(trees, edge.st, edge.ed);
//        }
//    }
//    return result;
//}

void testKruscal(){
    int N = 0, M = 0;
    int N1, N2, V;
    while(cin >> N >> M){
        vector<Edge> graph;
        while(M-- > 0){
            cin >> N1 >> N2 >> V;
            Edge edge(N1, N2, V);
            graph.push_back(edge);
        }
        // 排序
        sort(graph.begin(), graph.end(), [](const Edge& a, const Edge& b)->bool {return a.cost < b.cost; });
        vector<int> root(N + 1);
        for(int i = 1; i <= N; ++i){
            root[i] = i;
        }
        GraphHandler graphHandler;
        cout << graphHandler.Kruscal(root, graph) << endl;
    }
}

/**
 * 题型
 * */
// 133. Clone Graph
Node* GraphHandler::cloneGraph(Node* node){
    return NULL;
}