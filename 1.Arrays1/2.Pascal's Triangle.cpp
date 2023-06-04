#include<bits/stdc++.h>
using namespace std;

void display_matrix(vector<vector<int>>& arr)
{

    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//question 1
vector<vector<int>> pascal_triangle(int nrows)
{
    vector<vector<int>> arr={{1}};

    for(int i=0;i<nrows;i++)
    {
        vector<int> row(i+1);
        row[0]=row[i]=1;

        for(int j=1;j<i;j++)
        {
           row[j]= arr.back()[j-1]+arr.back()[j];
        }    

        arr.push_back(row);
    }

    return arr;
}

//question 2
vector<int> pascal_row(int nrows)
{
    vector<int> r(nrows);

    int res = 1;
    r[0]=r[nrows-1]=1;

    for(int i=1;i<nrows-1;i++)
    {
        res = res*(nrows-i);
        res = res/i;
        r[i]=res;
    }
    return r;
}

//question 3
int pascal_element(int row,int col)
{
    int res=1;

    for(int i=1;i<col;i++)
    {
        res = res*(row-i);
        res = res/i;
    }
    return res;
}

int main()
{
    vector<vector<int>> ans;

    ans = pascal_triangle(5);

    display_matrix(ans);

    vector<int> r;
    r = pascal_row(5);

    for(auto i: r)
    {
        cout<<i<<" "; 
    }
    cout<<endl<<endl;
    cout<<pascal_element(5,3);
}
