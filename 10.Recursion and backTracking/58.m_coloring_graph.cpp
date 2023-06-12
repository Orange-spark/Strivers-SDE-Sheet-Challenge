#include <bits/stdc++.h> 

bool isvalid(int node,int k,map<int,vector<int>>&g,unordered_map<int,int> &colors)
{
    for(auto i:g[node])
    {
        if(colors[i]==k)
            return false;
    }
    return true;
}

bool color_graph(map<int,vector<int>> &g,int m,unordered_map<int,int> &colors)
{
    int n = g.size();
    for(int i=0;i<n;i++)
    {
        if(colors[i]==0)
        {
            for(int k=1;k<=m;k++)
            {
                if(colors[i]==0 && isvalid(i,k,g,colors))
                {
                    colors[i] = k;
                    
                    if(color_graph(g,m,colors))
                        return true;
                    colors[i] =0;
                }
            }
            return false;
        }
    }
    return true;
}


string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    
    map<int,vector<int>> g;
    unordered_map<int,int> colors;
    
    int n =mat.size();
    for(int i=0;i<n;i++)
    {
        colors[i]=0;
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==1)
            {
                g[i].push_back(j);
            }
        }
    } 

    if(color_graph(g,m,colors)) return "YES";
    
    return "NO";
}

/* TO print the graph
    for(auto i:g)
    {
        cout<<i.first<<":";
        for(auto j:i.second)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }*/
