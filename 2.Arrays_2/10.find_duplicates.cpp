#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	vector<int> res(n,0);

	for(auto i:arr)
	{
		res[i]++;
	}

	for(int i=0;i<n;i++)
	{
		if(res[i]>1)
		 return i;
	}
}
