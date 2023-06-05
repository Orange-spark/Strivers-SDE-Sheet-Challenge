#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

bool comp(vector<int> &p,vector<int>&q)
{
    if(p[0]==q[0]) return p[1]<q[1];

    return p[0]<q[0];
}


vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;

    sort(arr.begin(),arr.end(),comp);

    ans.push_back(arr[0]);
    for(int i=1;i<arr.size();i++)
    {
        auto p = arr[i];

        if(p[0] <= ans.back()[1])
        {
            ans.back()[1] = max(p[1],ans.back()[1]);
        }   
        else
            ans.push_back(p);
    }

    return ans;
}
