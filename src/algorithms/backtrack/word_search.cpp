// Approach: Backtracking

#include <iostream>
#include <vector>

using namespace std;
bool isSafe(vector<vector<char>> &board, string &word, int index, int row, int col)
{
    if (row < 0 || row > board.size() || col < 0 || col > board[0].size() || board[row][col] != word[index])
        return false;
    return true;
}
// Function to perform DFS search
int nr[4] = {-1, 0, 1, 0};
int nc[4] = {0, -1, 0, 1};
bool dfs(vector<vector<char>> &board, string &word, int index, int row, int col)
{
    if (index == word.size())
        return true;
    for (int i = 0; i < 4; i++)
    {
        int new_r = nr[i] + row;
        int new_c = nc[i] + col;
        if (isSafe(board, word, index , new_r, new_c))
        {
            char temp = board[row][col];
            board[row][col] = '#';
            if (dfs(board, word, index + 1, new_r, new_c))
                return true;
            board[row][col] = temp;
        }
    }
    return false;
}

bool wordExists(vector<vector<char>> &board, string word)
{
    int rows = board.size();
    int cols = board[0].size();
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            // Start DFS if the first character matches
            if (board[row][col] == word[0] && dfs(board, word, 0, row, col))
            {
                return true;
            }
        }
    }
    return false;
}


// Optimization 
// Pruning: If the grid size is smaller than the word length, return false /immediately. 
// Visited Tracking: Instead of modifying the grid, use a separate visited array. 