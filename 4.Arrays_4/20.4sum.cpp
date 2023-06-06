#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.

    int sum = 0;

    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            sum = target - arr[i]-arr[j];

            int left = j+1,right= n-1;
            while(left<right)
            {
                int two_sum = arr[left]+arr[right];

                if(sum==two_sum)
                {
                    return "Yes";
                }
                if(two_sum<sum)
                {
                    while(left<right && arr[left]==arr[left+1])
                        left++;
                    left++;
                }
                else
                {
                    while(left<right && arr[right-1]==arr[right])
                        right--;
                    right--;
                }
            }

        }
    }

    return "No";
}
