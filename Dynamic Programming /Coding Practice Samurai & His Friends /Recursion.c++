#include <bits/stdc++.h>
using namespace std;
int maxChocolates(int i, int j1, int j2, vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (j1 < 0 || j2 < 0 || j1 > n - 1 || j2 > n - 1)
        return INT_MIN;
    if (i == m - 1) {
        if (j1 == j2)
            return grid[m - 1][j1];
        else
            return grid[m - 1][j1] + grid[m - 1][j2];
    }
    int grid_value;
    if (j1 == j2)
        grid_value = grid[i][j1];
    else
        grid_value = grid[i][j1] + grid[i][j2];
    int x[9];
    x[0] = maxChocolates(i + 1, j1 - 1, j2 - 1, grid);
    x[1] = maxChocolates(i + 1, j1 - 1, j2, grid);
    x[2] = maxChocolates(i + 1, j1 - 1, j2 + 1, grid);
    x[3] = maxChocolates(i + 1, j1, j2 - 1, grid);
    x[4] = maxChocolates(i + 1, j1, j2, grid);
    x[5] = maxChocolates(i + 1, j1, j2 + 1, grid);
    x[6] = maxChocolates(i + 1, j1 + 1, j2 - 1, grid);
    x[7] = maxChocolates(i + 1, j1 + 1, j2, grid);
    x[8] = maxChocolates(i + 1, j1 + 1, j2 + 1, grid);
    return grid_value + *max_element(x, x + 9);
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
    cout << maxChocolates(0, 0, n-1, grid);
    return 0;
}