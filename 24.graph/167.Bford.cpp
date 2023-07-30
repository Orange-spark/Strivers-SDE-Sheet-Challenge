#include <bits/stdc++.h> 

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {

    // Write your code here.

    vector<int> dist(n+1, 1e9);

    dist[src]=0;

    

    for(int i=0;i<n-1;i++){

        for(auto edge : edges){

            int u = edge[0], v=edge[1], wt=edge[2];

            if(dist[u]!=1e9 && dist[u]+wt < dist[v]){

                dist[v]=dist[u]+wt;

            }

        }

    }

    

    return dist[dest];

}
