#include <bits/stdc++.h> 
using namespace std;

void get_subset_sums(vector<int> &num,int ind,int n,int &sum,multiset<int> &res)
{
    if(ind==n)
    {
        res.insert(sum);
        return;
    }

    sum+=num[ind];
    get_subset_sums(num, ind+1,n, sum,res);
    sum-=num[ind];

    get_subset_sums(num, ind+1,n, sum,res);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.

    vector<int> ans;
    multiset<int> res;

    int sum=0;
    get_subset_sums(num,0,num.size(),sum,res);

    for(auto i:res)
        cout<<i<<" ";
    
    cout<<endl;

    return ans;
}   
