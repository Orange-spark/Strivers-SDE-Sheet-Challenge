#include<bits/stdc++.h>
using namespace std;

void add_board(vector<vector<int>> &board,vector<vector<int>> &res)
{
    vector<int> temp;
    for(auto i:board)
    {
        for(auto j:i)
        {
            // cout<<j<<" ";
            temp.push_back(j);
        }
        // cout<<endl;
    }
    res.push_back(temp);
}

bool isSafe(int x,int y,unordered_map<int,int> &queens)
{
    for(auto q:queens)
    {
        int i =q.first,j=q.second;
        if(i==x or j==y or x+y==i+j or y-x==j-i ) return false;
    }
    return true;
}

void place_queens(int x,int n,vector<vector<int>> &board,vector<vector<int>> &res,
unordered_map<int,int> &queens)
{
    if(n==queens.size())
    {
        //cout<<"hii";
        add_board(board,res);
        return;
    }
    if(x==n)
    {
        return;
    }

    for(int j=0;j<n;j++)
    {
        if(isSafe(x, j, queens))
        {
            queens[x] = j;
            board[x][j] =1;
            place_queens(x+1,n,board,res,queens); 
            queens.erase(x);
            board[x][j]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> board(n,vector<int>(n,0)),res;
    unordered_map<int,int> queens;

    place_queens(0,n,board,res,queens);

    return res;
}
