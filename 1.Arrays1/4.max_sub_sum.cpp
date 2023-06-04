#include<bits/stdc++.h>
using namespace std;

//brute force

/*void max_sum(vector<int> &arr,int ind,int &sum,int &maxi)
{
    if(ind>=arr.size()) return;

    sum+=arr[ind];
    maxi = max(sum,maxi);
    max_sum(arr,ind+1,sum,maxi);
        
    sum =0 ;
    max_sum(arr,ind+1,sum,maxi);

}
*/

int main()
{
    vector<int> arr ={1,2,7,-4,3,2,-10,9,1};

    int maxi=0,sum=0;

    //max_sum(arr,0,sum,maxi);

    for(auto i: arr)
    {
        sum+=i;

        maxi =max(maxi,sum);

        if(sum<0) sum =0;
    }

    cout<<maxi<<" ";
}
