#include <bits/stdc++.h>

int merge(vector<int> &arr, int start, int mid, int end) {
  
  int rev_pairs = 0;

  int k = 0,j=mid;

  	for(int i=start;i<mid;i++)
	{
		while(arr[i]>2*arr[j] && j<=end)
		{
			j++;
		}
		rev_pairs+=j-mid;
	}

    vector<int> temp(end-start+1);

	int left = start, right = mid;
	while(left<mid&&right<=end)
	{
		if(arr[left]<=arr[right])
			temp[k++]=arr[left++];

		else 
			temp[k++]=arr[right++];

	}

	while(left<mid)
	{
		temp[k++]=arr[left++];
	}

	while(right<=end)
	{
		temp[k++]=arr[right++];
	}

	k=0;
	for(int i =start;i<=end;i++)
	{
		arr[i] = temp[k++];
	}

	return rev_pairs;
}

int merge_sort(vector<int> &arr,int start,int end)
{
	int mid,rev_pairs =0;
	if(start<end)
	{
		mid = (start+end)/2;

		rev_pairs+=merge_sort(arr,start,mid);
		rev_pairs+=merge_sort(arr,mid+1,end);

		rev_pairs+=merge(arr,start,mid+1,end);

	}
	return rev_pairs;
}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.	

	return merge_sort(arr,0,n-1);
}
