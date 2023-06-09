#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.

    long left_max = 0,right_max=0,total =0;

    vector<long> rm(n);
    for(int i=n-1;i>=0;i--)
    {
        right_max = max(arr[i],right_max);
        rm[i] = right_max;
    }

    for(int i=0;i<n;i++)
    {   
        left_max = max(left_max,arr[i]);
        total += min(left_max,rm[i]) -arr[i];
    }

    return total;
}
