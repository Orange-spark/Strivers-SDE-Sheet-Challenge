#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here

    int coins=0,i=8;

    vector<int> den ={1,2,5,10,20,50,100,500,1000};
    while(amount)
    {
        coins+= amount/den[i];
        amount = amount % den[i];
        i--;
    }

    return coins;
}
