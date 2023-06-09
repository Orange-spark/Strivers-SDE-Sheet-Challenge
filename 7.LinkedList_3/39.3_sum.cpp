#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	vector<vector<int>> triplets;

	sort(arr.begin(),arr.end());

	int i=0;

	while(i<n)
	{
		int target  = K-arr[i];

		int left=i+1,right=n-1;

		while(left<right)
		{
			int sum =arr[left]+arr[right];
            //cout<<"sum "<<sum<<endl;
			if(sum==target)
			{
				triplets.push_back({arr[i],arr[left],arr[right]});
                
                while(left<right && arr[left]==arr[left+1]) left++;
				left++;

                while(left<right && arr[right]==arr[right-1]) right--;
				right--;
			}
			else if(sum<target)
			{
				left++;
			}
			else
			{
				right--;
			}
		//cout<<"left "<<arr[left]<<" right "<<arr[right]<<endl;
		}

		while(i<n && arr[i]==arr[i+1]) i++;
		
		i++;
	}

	return triplets;
}
