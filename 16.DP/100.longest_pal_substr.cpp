#include<bits/stdc++.h>

using namespace std;

 

int f(int i,int j,string &s){

    int n = s.size() , len = 0;

    while(i >= 0 && j < n && s[i--] == s[j++]) len += 2;

    return len;

}

 

string longestPalinSubstring(string s) {

   int n = s.size();

   int start = 0 , len = 0;

   for(int mid=0;mid<n;mid++){

       int odd = 1 + f(mid-1,mid+1,s);

       int even = f(mid,mid+1,s);

       if(len < odd) len = odd , start = mid-(odd/2);

       if(len < even) len = even , start = mid-(even/2)+1;

   }

   return s.substr(start,len);

}
