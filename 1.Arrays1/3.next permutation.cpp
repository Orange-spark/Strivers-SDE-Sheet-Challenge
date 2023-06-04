#include<bits/stdc++.h>
using namespace std;

//Brute force

/*void all_permutations(vector<int> &arr,int ind,vector<vector<int>> &ans)
{
    if(ind==arr.size()-1)
    {
        for(auto i: arr) cout<<i<<" ";
        cout<<endl;

        ans.push_back(arr);
        return; 
    }

    for(int i=ind;i<arr.size();i++)
    {
        swap(arr[i],arr[ind]);

        all_permutations(arr,ind+1,ans);

        swap(arr[i],arr[ind]);
    }

}*/

//optimal approach




int main()
{
    vector<int> arr ={1,2,3};
    
    //all_permutations(arr,0,ans);

    //next_permutation(arr.begin(),arr.end());

    int n = arr.size(),i = n-2;

    while(i>=00&&arr[i]>arr[i+1])
    {   
        i--;
    }
    
    if(i>=0)
    {
        int j=n-1;
        
        while(arr[j]<=arr[i]) j--;

        swap(arr[j],arr[i]);
    }
    reverse(arr.begin()+i+1,arr.end());

    for(auto p: arr)
    {
        cout<<p<<" ";
    }
}
