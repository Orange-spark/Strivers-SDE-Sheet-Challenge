#include<bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int,int>> works;

    int n=start.size();

    for(int i=0;i<n;i++)
    {
        works.push_back({end[i],start[i]});
    }

    sort(works.begin(),works.end());

    int cnt =1,end_time = works[0].first;

    for(int i=0;i<n;i++)
    {
        if(works[i].second>=end_time)
        {
            cnt++;
            end_time = works[i].first;
        }
    }
    return cnt;
}
