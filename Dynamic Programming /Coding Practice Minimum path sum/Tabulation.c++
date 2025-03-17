#include <bits/stdc++.h>
using namespace std;
int f(int m, int n, vector<vector<int>> &grid){
    vector<vector<int>> dp(m, vector<int>(n));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 && j==0) dp[0][0] = grid[0][0];
            else
                { 
                    int right = INT_MAX;
                    int down = INT_MAX;
                    if(j>0) right = dp[i][j-1];
                    if(i>0) down = dp[i-1][j];
                    dp[i][j] = grid[i][j] + min(right, down);
                }
        }
    }
    return dp[m-1][n-1];
}
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << f(m , n, grid);
    return 0;
}