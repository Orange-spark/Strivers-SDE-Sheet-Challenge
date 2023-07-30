#include <vector>

long f(int idx, int *denominations, int value, vector<vector<long>> &dp) {

if (idx == 0) {

return ((value % denominations[0]) == 0);

}

if (dp[idx][value] != -1) {

return dp[idx][value];

}

long notTake = f(idx - 1, denominations, value, dp);

long take = 0;

if (value >= denominations[idx]) {

take =f(idx, denominations, value - denominations[idx], dp);

}

return dp[idx][value] = notTake + take;

}

long countWaysToMakeChange(int *denominations, int n, int value) {

// Write your code here

vector<vector<long>> dp(n, vector<long>(value + 1, -1));

return f(n - 1, denominations, value, dp);

}#include <vector>

long f(int idx, int *denominations, int value, vector<vector<long>> &dp) {

if (idx == 0) {

return ((value % denominations[0]) == 0);

}

if (dp[idx][value] != -1) {

return dp[idx][value];

}

long notTake = f(idx - 1, denominations, value, dp);

long take = 0;

if (value >= denominations[idx]) {

take =f(idx, denominations, value - denominations[idx], dp);

}

return dp[idx][value] = notTake + take;

}

long countWaysToMakeChange(int *denominations, int n, int value) {

// Write your code here

vector<vector<long>> dp(n, vector<long>(value + 1, -1));

return f(n - 1, denominations, value, dp);

}
