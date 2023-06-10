#include <bits/stdc++.h> 

bool comp(pair<int, int> p, pair<int, int> q) {
    return p.second * q.first > q.second * p.first;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),comp);

    // cout<<endl;
    // for(auto i : items)
    // {
        
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    double profit =0;

    int i=0;
    while(i<n&&w!=0)
    {
        if(items[i].first<w)
        {
            w-=items[i].first;
            profit+=items[i].second;
        }
        else{
            profit += (w * static_cast<double>(items[i].second) / items[i].first);
            break;
        }
        //cout<<profit<<endl;
        i++;
    }

    return profit;
}
