#include <bits/stdc++.h> 

void help(int v,vector<int> &ans,vector<vector<int>> &ad,vector<int> &visited){

   queue<int>q;

   q.push(v);

   visited[v]=1;

   while(!q.empty()){

       int c=q.front();

       q.pop();

       ans.push_back(c);

       for(int i=0;i<ad[c].size();i++){

           if(visited[ad[c][i]]==0){

               visited[ad[c][i]]=1;

               q.push(ad[c][i]);

           }

       }

   }

}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)

{

    vector<int>ans;

    vector<vector<int>>ad(vertex,vector<int>());

    for(int i=0;i<edges.size();i++){

        int u=edges[i].first,v=edges[i].second;

        ad[u].push_back(v);

        ad[v].push_back(u);

    }

    for(int i=0;i<ad.size();i++){

        sort(ad[i].begin(),ad[i].end());

    }

   vector<int>visited(vertex,0);

   for(int i=0;i<vertex;i++){

       if(visited[i]==0){

           help(i,ans,ad,visited);

       }

   }

   return ans;

}
