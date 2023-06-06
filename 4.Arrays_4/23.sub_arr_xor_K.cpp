#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.

    int x_or=0,cnt=0;

    unordered_map<int,int> mp;

    for(int i=0;i<arr.size();i++)
    {
        x_or = x_or^arr[i];

        //cout<<x_or<<" ";
        if(x_or==x)
        {
            cnt++;
        }

            if(mp.count(x_or^x)!=0)
            {
                cnt+=mp[x_or^x];
            }
    
        mp[x_or]+=1;
    }

    return cnt;
}
