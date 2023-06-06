#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int s =0,maxi=0,n=arr.size();
  unordered_map<int,int> mp;

  for(int i=0;i<n;i++)
  {
    s+=arr[i];

    if(s==0) maxi =max(maxi,i+1);

    if(mp.count(s)!=0)
    {
      maxi = max(maxi,i-mp[s]);
    }
    else{
      mp[s]=i;
    }

  }
return maxi;
}
