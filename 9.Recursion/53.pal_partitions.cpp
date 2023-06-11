#include <bits/stdc++.h> 

bool isPal(string &s,int i,int j)
{
    while(i<j)
    {
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }   
    return true;
}

void get_pals(int last,int ind,string &s,vector<string> &temp,vector<vector<string>> &pals)
{
    int n= s.size();
    if(last == n-1)
    {
        // for(auto i:temp)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        pals.push_back(temp);
        return;
    }
    
    for(int i=last+1;i<n;i++)
    {
        if(isPal(s,last+1,i))
        {
            temp.push_back(s.substr(last+1,i-last));
            
            //cout<<s.substr(last+1,i+1);

            get_pals(i,i+1,s,temp,pals);
            temp.pop_back();
        }
    }

}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> pals;
    vector<string> temp;

    get_pals(-1,0,s,temp,pals);

    return pals;
}
