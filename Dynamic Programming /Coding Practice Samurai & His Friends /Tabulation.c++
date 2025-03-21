#include <bits/stdc++.h>
using namespace std;
int maxChocolates(int m, int n, vector<vector<int>>& grid) {
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n)));
    for (int i = m - 1; i >= 0; --i) {
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = 0; j2 < n; ++j2) {
                if(i == m-1){
                    if(j1 == j2)
                        dp[i][j1][j2] = grid[i][j1];
                    else
                        dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                }
                else{
                    int grid_value;
                    if (j1 == j2) {
                        grid_value = grid[i][j1];
                    } else {
                        grid_value = grid[i][j1] + grid[i][j2];
                    }
                    vector<int> x(9, INT_MIN);
                    if (j1 - 1 >= 0 && j2 - 1 >= 0)
                        x[0] = dp[i + 1][j1 - 1][j2 - 1];
                    if (j1 - 1 >= 0)
                        x[1] = dp[i + 1][j1 - 1][j2];
                    if (j1 - 1 >= 0 && j2 + 1 <= n - 1)
                        x[2] = dp[i + 1][j1 - 1][j2 + 1];
                    if (j2 - 1 >= 0)
                        x[3] = dp[i + 1][j1][j2 - 1];
                    x[4] = dp[i + 1][j1][j2];
                    if (j2 + 1 <= n - 1)
                        x[5] = dp[i + 1][j1][j2 + 1];
                    if (j1 + 1 <= n - 1 && j2 - 1 >= 0)
                        x[6] = dp[i + 1][j1 + 1][j2 - 1];
                    if (j1 + 1 <= n - 1)
                        x[7] = dp[i + 1][j1 + 1][j2];
                    if (j1 + 1 <= n - 1 && j2 + 1 <= n - 1)
                        x[8] = dp[i + 1][j1 + 1][j2 + 1];
                    int max_x = *max_element(x.begin(), x.end());
                    dp[i][j1][j2] = max_x + grid_value;
                }
            }
        }
    }
    return dp[0][0][n - 1];
}
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int> (n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            grid[i][j] = temp;
        }
    }
    cout << maxChocolates(m, n, grid);
    return 0;
}