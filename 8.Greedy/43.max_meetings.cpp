#include <bits/stdc++.h> 

static bool comp (pair<int,pair<int,int>> p,pair<int,pair<int,int>> q)
{
    if(p.first<q.first) return true;
    if(p.first>q.first) return false;

    if(p.second.second<q.second.second) return true;

    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    
    vector<pair<int,pair<int,int>>> mp;

    int n= start.size();
    for(int i=0;i<n;i++)
    {
        mp.push_back({end[i],{start[i],i+1}});
    }
    
    sort(mp.begin(),mp.end(),comp);

    int last = -1;

    vector<int> ans;

    for(int i=0;i<n;i++)
    {
        if(mp[i].second.first>last)
        {
            ans.push_back(mp[i].second.second);
            last = mp[i].first;
        }
    }

    return ans;
}
