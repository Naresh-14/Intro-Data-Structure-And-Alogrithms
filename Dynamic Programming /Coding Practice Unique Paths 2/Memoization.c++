#include<bits/stdc++.h>
using namespace std;
int uniquePathsII(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i < 0 || j < 0){
        return 0;
    }
    if(grid[i][j] == -1){
        return 0;
    }
    if(i == 0 && j == 0){
        return 1;
    }
    if(dp[i][j] != -1) return dp[i][j];
    int right = uniquePathsII(i, j-1, grid, dp);
    int down = uniquePathsII(i-1, j, grid, dp);
    return dp[i][j] = right + down;
}
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i< m; i++){
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            grid[i][j] = temp;
        }
    }
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << uniquePathsII(m-1, n-1, grid, dp);
    return 0;
}