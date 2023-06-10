#include<bits/stdc++.h>
using namespace std;

void get_subset_sums(vector<int> &arr,int ind,int &sum,int n,int k,vector<int> &temp,
vector<vector<int>> &subsets)
{
    if(ind == n)
    {
        if(sum==k) 
            subsets.push_back(temp);

        return;
    }

    temp.push_back(arr[ind]);
    sum+=arr[ind];
    get_subset_sums(arr,ind+1,sum,n,k,temp,subsets);
    sum-=arr[ind];
    temp.pop_back();

    get_subset_sums(arr,ind+1,sum,n,k,temp,subsets);

}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> subsets;
    vector<int> temp;

    int sum=0;
    get_subset_sums(arr,0,sum,n,k,temp,subsets);

    return subsets;
}
