#include <bits/stdc++.h>
using namespace std;
int f( int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if(i < 0 || j<0)
        return INT_MAX; 
        
    if(i==0 && j==0)
        return grid [0][0];
        
        
    int down = f(i-1,j,grid, dp);
    int right = f(i,j-1, grid, dp);
    
    return grid[i][j] + min (down, right);
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
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << f(m - 1, n - 1, grid, dp);
    return 0;
}