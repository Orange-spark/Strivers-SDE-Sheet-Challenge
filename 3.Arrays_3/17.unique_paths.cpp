#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.

	int n1 = m+n-2,r=n-1;

	int ans =1;

	for(int i=1;i<=r;i++)
	{
		ans = ans*(n1-i+1);
		ans= ans/i;
	}
	return ans;
}
