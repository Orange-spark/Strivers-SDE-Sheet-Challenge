#include<bits/stdc++.h>
using namespace std;
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.

    int platforms  =1,maxi=1;

    sort(at,at+n);
    sort(dt,dt+n);

    int i=1,j=0;
    
    while(i<n&&j<n)
    {
        if(at[i]<=dt[j])
        {
            platforms++;
            i++;
        }
        else 
        {    
            platforms--;
            j++;
        }
        maxi = max(maxi,platforms);
    }
    return maxi;
}
