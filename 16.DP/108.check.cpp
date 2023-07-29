#include <bits/stdc++.h> 

bool areAnagram(string &t, string &s){

         unordered_map<int, int> mp;

         unordered_map<int, int> ump;

 

         for(int i=0; i<t.size(); i++){

             mp[t[i]]++;

         }

         

         if(s.size() !=  t.size()){

             return false;

         }

         for(int i=0; i<s.size(); i++){

             ump[s[i]]++;

         }

         

         for(int i=0; i<t.size(); i++){

             int count = mp[t[i]];

         if(count > ump[t[i]]){

             return false;

         }

    }

        return true;

}
