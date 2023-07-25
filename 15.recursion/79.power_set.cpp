
#include <bits/stdc++.h> 

 

void powerSet(vector<int> v, vector<int> output, vector<vector<int>>& ans,int index){

    if(index>=v.size()){

        ans.push_back(output);

        return ;

    }

    //exclude

    powerSet(v,output,ans,index+1);

    //include

    output.push_back(v[index]);

    powerSet(v,output,ans,index+1);

}

 

vector<vector<int>> pwset(vector<int>v)

{

    //Write your code here

    vector<vector<int>> ans;

    vector<int> output;

    int index=0;

    powerSet(v,output,ans,index);

    return ans;

}
