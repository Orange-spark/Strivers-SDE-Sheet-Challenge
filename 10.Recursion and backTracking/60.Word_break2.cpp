#include <bits/stdc++.h> 

void get_sentences(int ind,int last,string &sent,string &s,set<string> &dict,vector<string> &sentences)
{
    //cout<<sent<<" "<<ind<<endl;
    int n=s.size();
    if(ind ==n)
    {
        sentences.push_back(sent);
        return;
    }

    for(int i=ind;i<n;i++)
    {
        string str = s.substr(last+1,i-last);

        //cout<<str<<endl;
        if(dict.count(str)!=0)
        {
            // cout<<str<<endl;
            if(i!=n-1) str+=" ";
            
            string temp = sent;

            sent = sent+str;
            
            get_sentences(i+1,i,sent,s,dict,sentences);

            sent = temp;
        }


    }

}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    set<string> dict;
    vector<string> sentences;

    for(auto i:dictionary)
        dict.insert(i);

    string sent="";

    get_sentences(0,-1,sent,s,dict,sentences);

    return sentences;
}
/* print set
    for(auto i:dict)
        cout<<i<<" - ";

    cout<<endl;
*/
