#include <bits/stdc++.h>

 

bool subsetSumToK(int n, int k, vector<int> &arr) {

 

 

 

vector<bool> prev(k+1),curr(k+1);

 

prev[0] = curr[0] = true;

 

prev[arr[0]] = true;

 

for(int i=1;i<n;i++){

 

curr[arr[i]] = true;

for(int target = 1;target <= k; target++){

 

bool notTake = prev[target];

 

bool Take = false;

 

if( arr[i] <= target){

 

Take |= prev[target - arr[i]];

 

}

 

curr[target] = Take | notTake;

 

}

prev = curr;

 

}

 

return prev[k];

 

}
