#include <bits/stdc++.h> 
int f(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
    if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
    if(i>=grid.size() || j>=grid[0].size()) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int down=grid[i][j]+f(grid,i+1,j,dp);
    int right=grid[i][j]+f(grid,i,j+1,dp);
    return dp[i][j]=min(down,right);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
    return f(grid,0,0,dp);
}
