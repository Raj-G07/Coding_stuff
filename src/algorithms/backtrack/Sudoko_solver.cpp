// Backtracking function to solve the Sudoku

#include <iostream>
#include <vector>

using namespace std;

void printGrid(vector<vector<int>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>> &grid, int row, int col, int num)
{
    // rows
    for (int i = 0; i < grid[0].size(); i++)
    {
        if (grid[row][i] == num)
            return false;
    }
    // colums
    for (int i = 0; i < grid.size(); i++)
    {
        if (grid[i][col] == num)
            return false;
    }
    // sub-grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>> &grid)
{
    int start_row = -1, start_col = -1;
    bool isEmpty = false;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                start_row = i;
                start_col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
            break;
    }

    if (!isEmpty)
        return true;

    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(grid, start_row, start_col, i))
        {
            grid[start_row][start_col] = i;
            if (solveSudoku(grid))
            {
                return true;
            }
            grid[start_row][start_col] = 0;
        }
    }
    return false;
}