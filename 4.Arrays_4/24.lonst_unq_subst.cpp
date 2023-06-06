#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int maxi =1,start=0,i=0,n=input.size();

    unordered_map<char,int> mp;

    while(i<n)
    {
        if(mp.count(input[i]))
       {
           start = max(mp[input[i]]+1,start);
       }

       mp[input[i]]=i;
       maxi = max(maxi,i-start+1);
       i++;
    }
    return maxi;
}
