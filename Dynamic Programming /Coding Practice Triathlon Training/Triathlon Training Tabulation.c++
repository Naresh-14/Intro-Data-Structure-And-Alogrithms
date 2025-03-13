#include <bits/stdc++.h>
using namespace std;


int training(int n, vector<vector<int>> &points )
{
    
    vector<vector<int>> dp(n,vector<int>(3));
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    
    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<=2;j++)
        {
            dp[i][j] = points[i][j] + max(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]);
        }
    }
    
    
    int a = dp[n-1][0];
    int b = dp[n-1][1];
    int c = dp[n-1][2];
    return max( max(a, b), c);
}



int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>points[i][j];
        }
    }
    cout<<training(n,points);
    return 0;
}