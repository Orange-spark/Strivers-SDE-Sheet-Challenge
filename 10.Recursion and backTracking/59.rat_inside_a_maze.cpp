#include <bits/stdc++.h> 
using namespace std;

bool isvalid(int x, int y, int n)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n))
        return true;

    return false;
}

void add_result(vector<vector<int>>& paths, vector<vector<int>>& maze)
{
  vector<int> temp;
    for (int i = 0; i < maze.size(); i++)
    {
        
        for (int j = 0; j < maze.size(); j++)
        {
            if (maze[i][j] == 2)
                temp.push_back(1);
            else
                temp.push_back(0);
        }
    }
    paths.push_back(temp);
}

void find_path(int x, int y, vector<vector<int>>& paths, vector<vector<int>>& maze)
{
    int n = maze.size();
    if (x == n - 1 && y == n - 1)
    {
        maze[x][y] = 2;
        add_result(paths, maze);
        maze[x][y] =1;
        return;
    }

    if (isvalid(x - 1, y, n) && maze[x - 1][y] == 1)
    {
        maze[x - 1][y] = 2;
        find_path(x - 1, y, paths, maze);
        maze[x - 1][y] = 1;
    }
    if (isvalid(x, y - 1, n) && maze[x][y - 1] == 1)
    {
        maze[x][y - 1] = 2;
        find_path(x, y - 1, paths, maze);
        maze[x][y - 1] = 1;
    }
    if (isvalid(x + 1, y, n) && maze[x + 1][y] == 1)
    {
        maze[x + 1][y] = 2;
        find_path(x + 1, y, paths, maze);
        maze[x + 1][y] = 1;
    }
    if (isvalid(x, y + 1, n) && maze[x][y + 1] == 1)
    {
        maze[x][y + 1] = 2;
        find_path(x, y + 1, paths, maze);
        maze[x][y + 1] = 1;
    }
}

vector<vector<int>> ratInAMaze(vector<vector<int>>& maze, int n)
{
    vector<vector<int>> paths;

    if (maze[0][0] == 0)
        return paths;

    maze[0][0] = 2;
    find_path(0, 0, paths, maze);
    maze[0][0] = 1;

    return paths;
}
