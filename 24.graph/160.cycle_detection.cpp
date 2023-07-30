bool dfs(int i,vector<vector<int>> &ad,vector<int> &visited,int parent){

    visited[i]=1;

    for(auto n:ad[i]){

        if(visited[n]==1){

            if(n!=parent)return true;

        }else{

            if(dfs(n,ad,visited,i))return true;

        }

    }

    return false;

}

string cycleDetection (vector<vector<int>>& edges, int n, int m)

{

    // Write your code here.

    vector<vector<int>>ad(n+1);

    for(int i=0;i<m;i++){

        ad[edges[i][0]].push_back(edges[i][1]);

        ad[edges[i][1]].push_back(edges[i][0]);

    }

    vector<int>visited(n+1,0);

    for(int i=1;i<=n;i++){

        if(visited[i]==0){

            if(dfs(i,ad,visited,-1))return "Yes";

        }

    }

    return "No";

}

 
