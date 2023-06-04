#include <bits/stdc++.h> 
int maximumProfit(vector<int> &arr){
    // Write your code here.
    int n=arr.size();

    int mini = arr[0],profit=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i] < mini)
        {
            mini = arr[i];
        }

        if(arr[i]>mini)
        {
            profit = max(profit,arr[i]-mini);
        }
    }
    return profit;
}
