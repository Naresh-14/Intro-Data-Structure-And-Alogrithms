#include <bits/stdc++.h>
using namespace std;


int f(int i, int sport, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if(i < 0)
        return 0;
    if(dp[i][sport]!=-1)
        return dp[i][sport];
        
    int left = f(i-1, (sport+1)%3, points,dp);
    int right = f(i-1, (sport+2)%3, points,dp);
    int ans = points[i][sport] + max( left, right) ;
    return dp[i][sport] = ans;
}

int training(int n, vector<vector<int>> &points )
{
    vector<vector<int>> dp(n,vector<int>(3,-1));
    int a = f(n-1, 0, points,dp);
    int b = f(n-1, 1, points,dp); 
    int c = f(n-1, 2, points,dp);
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