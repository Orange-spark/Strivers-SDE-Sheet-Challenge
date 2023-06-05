#include <bits/stdc++.h> 

long long merge(long long *arr,int start,int mid,int end)
{
    long long inv_cnt = 0;

    int left = start,right =mid;

    vector<long long> temp(end-start+1);

    int k=0;

    while(left<=mid-1 && right<=end)
    {
        if(arr[left]<=arr[right])
        {
            temp[k++] = arr[left];
            left++;
        }
        else{
            temp[k++] = arr[right];
            right++;  
            inv_cnt+= (mid-left);

        }
    }
    while(left<=mid-1)
    {
        temp[k++] = arr[left];
        left++;
    }

    while(right<=end)
    {
        temp[k++] = arr[right];
        right++;  
    }

    k=0;
    for(int i = start ; i <=end ; i++)
        arr[i] = temp[k++];

 return inv_cnt;   
}

long long merge_sort(long long *arr,int start,int end)
{
    if(start<end)
    {
        long long inv_cnt = 0;

        int mid = (start+end)/2;

        inv_cnt+=merge_sort(arr,start,mid);
        inv_cnt+=merge_sort(arr,mid+1,end);
        inv_cnt+=merge(arr,start,mid+1,end);

        return inv_cnt;
    }
    return 0;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return merge_sort(arr,0,n-1);
}
