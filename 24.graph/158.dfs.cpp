void help(int v,vector<int> &visited,vector<vector<int>> &ad,vector<int> &t){

    visited[v]=1;

    t.push_back(v);

    for(int i=0;i<ad[v].size();i++){

        if(visited[ad[v][i]]==0){

            help(ad[v][i],visited,ad,t);

        }

    }

}

vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges)

{

    // Write your code here

    vector<vector<int>>ans;

    vector<vector<int>>ad(v,vector<int>());

    for(int i=0;i<edges.size();i++){

        int u=edges[i][0],v=edges[i][1];

        ad[u].push_back(v);

        ad[v].push_back(u);

    }

   for(int i=0;i<v;i++){

       sort(ad[i].begin(),ad[i].end());

   }

   vector<int>visited(v,0);

   for(int i=0;i<v;i++){

       if(visited[i]==0){

           vector<int>t;

           help(i,visited,ad,t);

           ans.push_back(t);

       }

   }

   return ans;

}
