#include<bits/stdc++.h>
using namespace std;
int path_sum(int i, int j, vector<vector<int>> &grid, int m, int n){
    if(j < 0 || j > n-1){
        return INT_MIN;
    }
    if(i == m-1){
        return grid[m-1][j];
    }
    int left_d = path_sum(i+1, j-1, grid, m, n);
    int down = path_sum(i+1, j, grid, m, n);
    int right_d = path_sum(i+1, j+1, grid, m, n);
    int temp = max(left_d, down);
    int maximum_sum = max(temp, right_d);
    return grid[i][j] + maximum_sum;
}
int max_path_sum(int m, int n, vector<vector<int>> &grid){
    int ans = INT_MIN;
    for(int j = 0; j <= n-1; j++){
        int x = path_sum(0, j, grid, m, n);
        if(x > ans){
            ans = x;
        }
    }
    return ans;
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
    cout << max_path_sum(m, n, grid);
    return 0;
}