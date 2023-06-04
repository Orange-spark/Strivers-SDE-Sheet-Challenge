#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &ans, int n, int m)
{
    // Write your code here
    
    int row,col,r1=0,r2= ans.size()-1,c1=0,c2 = ans[0].size()-1;

    while(r1<r2 && c1<c2)
    {
        int i=r1,j=c2;

        row = ans[i][j];
        while(j>c1)
        {
            ans[i][j] = ans[i][j-1];
            j--;
        }
        ans[i][j] = ans[i+1][j];
        r1++;

        i=r2,j=c2;
        col = ans[i][j];
        while(i>r1)
        {
            ans[i][j] = ans[i-1][j];
            i--;
        }
        ans[i][j]=row;
        c2--;
    if(c1<=c2)
    {   i=r2,j=c1;
        row = ans[i][j];
        while(j<c2)
        {
            ans[i][j] = ans[i][j+1];
            j++;
        }
        ans[i][j]=col;
        r2--;
    }
    if(r1<=r2)
     {   i=r1,j=c1;
        while(i<r2)
        {
            ans[i][j]=ans[i+1][j];
            i++;
        }
        ans[i][j]=row;
        c1++;
     }
        
    }
}
