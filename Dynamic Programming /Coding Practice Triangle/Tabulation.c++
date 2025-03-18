#include <bits/stdc++.h>
using namespace std;
int minimum_sum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n,vector<int>(n));

    for(int j=0; j<=n-1; j++)
    {
        dp[n-1][j] = triangle[n-1][j];
    }
        
    for(int i=n-2;i>=0; i--)
    {
        for(int j=0; j<=i; j++)
        {
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> triangle(n);

    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }

    cout << minimum_sum(triangle, n);

    return 0;
}