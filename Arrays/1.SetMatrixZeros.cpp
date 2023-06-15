#include<bits/stdc++.h>
using namespace std;

void display_matrix(vector<vector<int>>& arr)
{
    cout<<endl;

    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//1.Brute force method

/* void set_row_zero(int row,vector<vector<int>> &arr)
{
        for(int j=0;j<arr[0].size();j++)
        {
            if(arr[row][j]!=0)
            {
                arr[row][j]=-1;
            }
        } 
}

void set_col_zero(int col,vector<vector<int>> &arr)
{
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i][col]!=0)
            {
                arr[i][col]=-1;
            }
        } 
}

void set_matrix_zeros(vector<vector<int>> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            if(arr[i][j]==0)
            {
                set_row_zero(i,arr);
                set_col_zero(j,arr);
            }
        } 
    }    
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            if(arr[i][j]==-1)
            {
                arr[i][j]=0;
            }
        } 
    }
}
*/

//2. better approach

/* void set_matrix_zeros(vector<vector<int>> &arr)
{
    vector<int> row(arr.size(),-1);
    vector<int> col(arr[0].size(),-1);

    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            if(arr[i][j]==0)
            {
                row[i]=0;
                col[j]=0;
            }
        } 
    }    

    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            if(col[j]==0 or row[i]==0)
            {
                arr[i][j]=0;
            }
        } 
    }    

}
*/

//3 optimal approach

void set_matrix_zeros(vector<vector<int>> &arr)
{
    int col=-1;

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i][0]==0) col=0;

        for(int j=1;j<arr[0].size();j++)
        {
            if(arr[i][j]==0)
            {
                arr[0][j]=0;

                arr[i][0] = 0;
            }
        } 
    }    

    for(int i=arr.size()-1;i>=0;i--)
    {
        for(int j=arr[0].size()-1;j>0;j--)
        {
            if(arr[0][j]==0 or arr[i][0]==0)
                {
                    arr[i][j]=0;
                } 
        } 
        if(col==0) arr[i][0] = 0;
    }    
}


int main()
{
    vector<vector<int>> ans = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    

    set_matrix_zeros(ans);

    display_matrix(ans);
}
