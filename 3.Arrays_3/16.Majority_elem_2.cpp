#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.

    vector<int> ans;

    int cnt1=0,cnt2=0,n1=0,n2=0;

    for(int i=0;i<arr.size();i++)
	{
		if(cnt1==0)
			n1=arr[i];
		else 
			if(cnt2==0)
				n2=arr[i];
		
		if(arr[i]==n1) cnt1++;
		else 
			if(arr[i]==n2) cnt2++;
			else 
			{
				cnt2--,cnt1--;
			}
    }
	
	cnt1=0,cnt2=0;

	for(auto i:arr)
	{
		if(i==n1) cnt1++;

		else if(i==n2) cnt2++;
	}

	if(cnt1>arr.size()/3) ans.push_back(n1);
	if(cnt2>arr.size()/3) ans.push_back(n2);

    return ans;
}
