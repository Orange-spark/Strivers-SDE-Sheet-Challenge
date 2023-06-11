#include<bits/stdc++.h>
using namespace std;

bool isValid(int x,int y,int n,int matrix[][9])
{
    
    for(int i=0;i<9;i++)
    {
        if(matrix[x][i]==n) return false;
  
        if(matrix[i][y]==n) return false;

        if(matrix[3*(x/3)+i/3][3*(y/3)+i%3]==n)
            return false;
        
    }
    return true;
}

bool final(int matrix[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(matrix[i][j]==0)
            {
                for(int k=1;k<=9;k++)
                {
                    if(isValid(i,j,k,matrix))
                    {    
                        matrix[i][j] = k;
                        if(final(matrix))
                            return true;
                        else
                            matrix[i][j]=0;
                    } 
                }
                return false;
            }
            
        }
    }

    return true;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.

    return final(matrix);
}
