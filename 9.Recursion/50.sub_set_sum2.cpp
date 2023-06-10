#include <bits/stdc++.h> 

void get_sub_sets(vector<int> &arr,int ind,int n,vector<int> &temp,set<vector<int>> &subsets)
{
    if(ind==n)
    {
        subsets.insert(temp);
        return;
    }


    int j=ind+1;

    get_sub_sets(arr,j,n,temp,subsets);
    //cout<<"j"<<j<<" "<<endl;
    temp.push_back(arr[ind]);

    get_sub_sets(arr,j,n,temp,subsets);

    temp.pop_back();


}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>> subsets;
    vector<vector<int>> ans;
    vector<int> temp;
    
    sort(arr.begin(),arr.end());

    get_sub_sets(arr,0,n,temp,subsets);
    
    for(auto i:subsets)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    

    return ans;
}
