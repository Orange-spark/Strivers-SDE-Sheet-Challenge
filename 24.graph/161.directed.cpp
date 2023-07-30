#include<bits/stdc++.h>

 

bool dfs(int node,vector<int>adjL[],int vis[],int pathVis[]){

  vis[node]=1;

  pathVis[node]=1;

 

  for(auto it:adjL[node]){

    

    if(!vis[it]){

      if(dfs(it,adjL,vis,pathVis)==true)return true;

      

    }

    else if(pathVis[it]==1)return true;

  }

  pathVis[node]=0;

 

  return false;

 

  

}

 

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

 

  vector<int>adjL[n+1];

  

  for(auto it:edges){

    adjL[it.first].push_back(it.second);

 

  }

 

  int vis[n+1]={0};

  int pathVis[n+1]={0};

 

  for(int i=0;i<=n;i++){

    if(!vis[i]){

     

        if(dfs(i, adjL, vis, pathVis)==true)return true;

        

      

    }

    

  }

 

  return false;

 

}
