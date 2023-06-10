#include <bits/stdc++.h> 

static bool comp(vector<int> a,vector<int> b)
{
    if(a[1]==b[1])return a[0]<b[0];

    return a[1]>b[1];
}


int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here

    int n= jobs.size(),profit = 0;
    vector<int> time(3000,-1);

    sort(jobs.begin(),jobs.end(),comp);

    // cout<<endl;
    // for(auto i:jobs)
    // {
    //     for(auto j:i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }


    for(int i=0;i<n;i++)
    {
        int j = jobs[i][0];

        while(j>0&&time[j]!=-1)
        {
            j--;
        }

        if(j>0)
        {
            profit+=jobs[i][1];
            time[j]=1;
        }
    }

    // for(auto j:time)
    // {
    //     cout<<j<<" ";
    // }
    // cout<<endl;

    return profit;
}
