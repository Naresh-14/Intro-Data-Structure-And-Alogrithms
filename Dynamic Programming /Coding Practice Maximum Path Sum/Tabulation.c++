#include<bits/stdc++.h>
using namespace std;
int max_path_sum(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for(int i = m-1; i >= 0; i--){
        for(int j = 0; j <= n-1; j++){
            if(i == m-1){
                dp[i][j] = grid[m-1][j];
            }
            else{
                int left_d = INT_MIN, right_d = INT_MIN;
                if(j > 0){
                    left_d = dp[i+1][j-1];
                }
                int down = dp[i+1][j];
                if(j <= n-2){
                    right_d = dp[i+1][j+1];
                }
                dp[i][j] = grid[i][j] + max( max(left_d, down), right_d);
            }
        }
    }
    return *max_element(dp[0].begin(), dp[0].end());
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
    cout << max_path_sum(grid);
    return 0;
}