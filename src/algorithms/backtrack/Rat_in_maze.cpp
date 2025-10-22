// Rat in a Maze

#include <iostream>
#include <vector>

using namespace std;

// Directions for moving in the maze: down, left, right, up

int rowDir[] = {1, 0, 0, -1};
int colDir[] = {0, -1, 1, 0};
char moves[] = {'D', 'L', 'R', 'U'};

bool isValidMove(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &visited, int n)
{
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && visited[x][y] == 0);
}

// Backtracking function to find all paths
void findPaths(int x, int y, vector<vector<int>> &maze, int n, vector<vector<int>> &visited, string &path, vector<string> &paths)
{
    // Base case: Destination reached
    if (x == n - 1 && y == n - 1)
    {
        paths.push_back(path);
        return;
    }
    // Mark the current cell as visited
    visited[x][y] = 1;
    // Explore all possible directions
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + rowDir[i];
        int nextY = y + colDir[i];
        if (isValidMove(nextX, nextY, maze, visited, n))
        {
            // Add the move to the path
            path.push_back(moves[i]);
                findPaths(nextX, nextY, maze, n, visited, path, paths);
            // Backtrack: Remove the move from the path
            path.pop_back();
        }
    }
    // Unmark the current cell
    visited[x][y] = 0;
}

vector<string> solveMaze(vector<vector<int>> &maze, int n)
{
    vector<string> paths;
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
    {
        return paths; // No solution if start or end is blocked
    }
    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    findPaths(0, 0, maze, n, visited, path, paths);
    return paths;
}