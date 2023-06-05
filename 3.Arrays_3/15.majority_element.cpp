#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.

	int cnt1 =0,ele;

	for(int i=0;i<n;i++)
	{
		if(arr[i]==ele) cnt1++;
		
		else
		{
			if (cnt1 == 0) 
			{
				ele = arr[i];
			} 
			else
				cnt1--;
        }
    }
	cnt1=0;

	for(int i=0;i<n;i++)
	{
		if(ele==arr[i])
		 cnt1++;
	}
	//cout<<cnt1<<" "<<endl;

	if(cnt1>n/2) return ele;

	return -1;
}
