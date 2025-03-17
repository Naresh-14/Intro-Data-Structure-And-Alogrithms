#include <bits/stdc++.h>
using namespace std;
int f(int m, int n, vector<vector<int>> &grid){
    vector<int> prev(n);
    vector<int> cur(n);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 && j==0) cur[j] = grid[0][0];
            else
                { 
                    int right = INT_MAX;
                    int down = INT_MAX;
                    if(j>0) right = cur[j-1];
                    if(i>0) down = prev[j];
                    cur[j] = grid[i][j] + min(right, down);
                }
        }
        prev=cur;
    }
    return cur[n-1];
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
    cout << f(m , n, grid);
    return 0;
}