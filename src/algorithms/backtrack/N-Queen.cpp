// Backtracking function to solve the N-Queens problem

#include <iostream>
#include <vector>

using namespace std;

void printSolution(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << (board[i][j] ? "Q" : ".") << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>> &board, int row, int col)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][col])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j])
            return false;
    }
    return true;
}

bool solveNQueensUtil(vector<vector<int>> &board, int row)
{
    int N = board.size();
    if (row == N)
        return true;
    for (int i = 0; i < board[0].size(); i++)
    {
        if (isSafe(board, row, i))
        {
            board[row][i] = 1;
            if (solveNQueensUtil(board, row + 1))
                return true;
            board[row][i] = 0;
        }
    }
    return false;
}

void solveNQueens(int N)
{
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (!solveNQueensUtil(board, 0))
    {
        cout << "No solution exists for N = " << N << endl;
    }
}