#include <bits/stdc++.h> using namespace std;

int solve(int i, int j, string s, string t, vector<vector<int>> &dp) 
{    
	if (i < 0 || j < 0)        
		return 0;

   if (dp[i][j] != -1)        
   		return dp[i][j];

   if (s[i] == t[j])        
   		return dp[i][j] = 1 + solve(i - 1, j - 1, s, t, dp);
	else        
		return dp[i][j] = max(solve(i, j - 1, s, t, dp), solve(i - 1, j, s, t, dp)); }

int lcs(string s, string t) 
{    
	int M = s.length();    
	int N = t.length();

   vector<vector<int>> dp(M, vector<int>(N, -1));

   return solve(M - 1, N - 1, s, t, dp); 
} 
