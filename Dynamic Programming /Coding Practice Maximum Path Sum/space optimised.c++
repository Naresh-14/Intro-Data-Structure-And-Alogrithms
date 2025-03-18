#include<bits/stdc++.h>
using namespace std;
int max_path_sum(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n);
    vector<int> cur(n);
    for(int i = m-1; i >= 0; i--){
        for(int j = 0; j <= n-1; j++){
            if(i == m-1){
                cur[j] = grid[m-1][j];
            }
            else{
                int left_d = INT_MIN, right_d = INT_MIN;
                if(j > 0){
                    left_d = prev[j-1];
                }
                int down = prev[j];
                if(j <= n-2){
                    right_d = prev[j+1];
                }
                cur[j] = grid[i][j] + max( max(left_d, down), right_d);
            }
        }
        prev = cur;
    }
    return *max_element(cur.begin(), cur.end());
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