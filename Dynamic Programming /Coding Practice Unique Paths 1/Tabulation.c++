#include<bits/stdc++.h>
using namespace std;
int uniquePaths(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n));
    for(int j = 0; j <= n-1; j++){
        dp[0][j] = 1;
    }
    for(int i = 1; i <= m-1; i++){
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m-1; i++){
        for(int j = 1; j <= n-1; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
int main() {
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n);
    return 0;
}