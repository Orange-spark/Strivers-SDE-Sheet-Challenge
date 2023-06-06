#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> ans;

   sort(arr.begin(),arr.end());

   int i=0,j=arr.size()-1;

   while(i<j)
   {
      int temp = arr[i]+arr[j];

      if(temp==s)
      {
         int k =j;

         while(k>i&&arr[k]==arr[j])
         {  
            vector<int> v;
            v.push_back(arr[i]);
            v.push_back(arr[k--]);
            ans.push_back(v);
         }
         i++;
      }
      else if(temp<s)
      {
         i++;
      }
      else j--;
   }

   return ans;
}
