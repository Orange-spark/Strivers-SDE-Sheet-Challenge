#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 

	int x1=0,b1=0,b2=0;

	for(int i=0;i<n;i++)
	{
		x1 = x1^arr[i];
		x1=x1^(i+1);
	}
	
	int nr = x1&~(x1-1);

	for(int i=0;i<n;i++)
	{
		if(nr&arr[i])
		{
			b1=b1^arr[i];
		}
		else 
			b2=b2^arr[i];
	}

	for(int i=1;i<=n;i++)
	{
		if(nr&i)
		{
			b1=b1^i;
		}
		else 
			b2=b2^i;
	}

	for(int i=0;i<n;i++)
	{
		if(arr[i]==b1)
		{
			return {b2,b1};	
		}
		if(arr[i]==b2)
		{
			return {b1,b2};	
		}

	}

	return {b1,b2};
	
}
