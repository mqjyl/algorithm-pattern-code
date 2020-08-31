//
// Created by mqjyl on 2020/8/12.
//

#include "../BFS_DFS.h"
using namespace std;

void setY(std::vector<std::vector<char>>& board, int x, int y, int xLen, int yLen){
    if(x == 0 || x == xLen - 1 || y == 0 || y == yLen - 1)
        return;
    if(board[x][y] != 'O')
        return;
    board[x][y] = 'Y';
    setY(board, x + 1, y, xLen, yLen);
    setY(board, x - 1, y, xLen, yLen);
    setY(board, x, y + 1, xLen, yLen);
    setY(board, x, y - 1, xLen, yLen);
}

// 130. 被围绕的区域
void BFS_DFS::solve(std::vector<std::vector<char>>& board){
    if(board.empty())
        return;
    int xlen = board.size();
    int ylen = board[0].size();
    // 顺时针沿着边界走一圈 设置 O -> Y
    for(int i = 0; i < ylen; ++i){
        if(board[0][i] == 'O'){
            board[0][i] = 'Y';
            setY(board, 1, i, xlen, ylen);
        }
        if(board[xlen - 1][i] == 'O'){
            board[xlen - 1][i] = 'Y';
            setY(board, xlen - 2, i, xlen, ylen);
        }
    }
    for(int i = 1; i < xlen - 1; ++i){
        if(board[i][0] == 'O'){
            board[i][0] = 'Y';
            setY(board, i, 1, xlen, ylen);
        }
        if(board[i][ylen - 1] == 'O'){
            board[i][ylen - 1] = 'Y';
            setY(board, i, ylen - 2, xlen, ylen);
        }
    }

    // 遍历一遍 O -> X , Y -> O
    for(int i = 0; i < xlen; ++i){
        for(int j = 0; j < ylen; ++j){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            if(board[i][j] == 'Y')
                board[i][j] = 'O';
        }
    }
}