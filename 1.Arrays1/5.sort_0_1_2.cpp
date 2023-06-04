#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int zer=0,one=0;

   for(int i=0;i<n;i++)
   {
      if(arr[i]==0) zer++;
      else if(arr[i]==1) one++;
   }

   for(int i=0;i<n;i++)
   {
      if(zer!=0)
      {
         arr[i]=0;
         zer--;
      } else if (one != 0)
       {
        arr[i] = 1;
        one--;
      } else
        arr[i] = 2;
   }

}
