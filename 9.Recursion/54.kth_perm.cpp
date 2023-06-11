
void get_perm(string &s,int k,int fact,string &res)
{
    
    while(s.size()!=0)
    {   
        int n=s.size();
        int ind = k/(fact/n);
        
        k = k%(fact/n);

        res = res+ s[ind];

        s = s.substr(0,ind)+s.substr(ind+1,n-ind);

        fact =fact/n;

    }
}

string kthPermutation(int n, int k) {
    // Write your code here.
    string s="",r="";
    int fact=1;

    for(int i=1;i<=n;i++)
    {
        s+=to_string(i);
        fact*=i;
    }

    //cout<<s<<endl;
    //cout<<fact<<endl;
    get_perm(s,k-1,fact,r);

    return r;
}
