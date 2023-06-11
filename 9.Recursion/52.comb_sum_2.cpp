#include<bits/stdc++.h>
using namespace std;

void get_subset_sums(vector<int> &arr, int ind, int sum, int n, int k, vector<int> &temp, set<vector<int>> &subsets)
{
    if (sum == k)
    {
        subsets.insert(temp);
    }

    if (ind == n)
    {
        return;
    }

    for (int i = ind; i < n; i++)
    {
        temp.push_back(arr[i]);
        sum += arr[i];
        get_subset_sums(arr, i + 1, sum, n, k, temp, subsets);
        sum -= arr[i];
        temp.pop_back();

        // Skip duplicates
        while (i < n - 1 && arr[i] == arr[i + 1])
        {
            i++;
        }
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<vector<int>> ans;
    set<vector<int>> combinations;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    int sum = 0;
    get_subset_sums(arr, 0, sum, n, target, temp, combinations);

    for (auto i : combinations)
    {
        ans.push_back(i);
    }

    return ans;
}
