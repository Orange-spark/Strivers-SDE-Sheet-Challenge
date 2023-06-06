#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.

    unordered_set<int> mp;

    int maxi =1;

    for(auto i:arr)
    {
        mp.insert(i);
    }

    for(auto i:mp)
    {
       if(mp.count(i-1)==0)
       {
           int n = i;
           int cnt =1;

           while(mp.count(n+1))
           {
               cnt++;
               n++;
           }

           maxi =max(maxi,cnt);
       }
    }
    return maxi;
}

