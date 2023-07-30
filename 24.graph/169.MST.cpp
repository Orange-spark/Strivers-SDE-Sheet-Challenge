#include <bits/stdc++.h> 

using namespace std;

 

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)

{

    vector<vector<vector<int>>> graph(n+1);

    for(auto edge : g){

        int u = edge.first.first, v=edge.first.second, wt=edge.second;

        graph[u].push_back({v, wt});

        graph[v].push_back({u, wt});

    }

 

    vector<pair<pair<int, int>, int>> ans;

    vector<bool> vis(n+1, false);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {1, -1}});

 

    while(!pq.empty()){

        auto it = pq.top();

        pq.pop();

 

        int wt = it.first, currNode = it.second.first, currParent = it.second.second;

        if(vis[currNode])

            continue;

        vis[currNode]=true;

        ans.push_back({{currNode, currParent}, wt});

        for(auto edge : graph[currNode]){

            int nbr = edge[0], nbrWt=edge[1];

            if(!vis[nbr]){

                pq.push({nbrWt, {nbr, currNode}});

            }

        }

    }

    ans.erase(ans.begin(), ans.begin()+1);

    return ans;

}

 
