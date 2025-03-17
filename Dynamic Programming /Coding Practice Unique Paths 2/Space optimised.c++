#include<bits/stdc++.h>
using namespace std;
int uniquePathsII(int m, int n, vector<vector<int>>& grid) {
    vector<int> prev(n);
    vector<int> cur(n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == -1) {
                cur[j] = 0;
            }
            else if (i == 0 && j == 0) {
                cur[0] = 1;
            }
            else {
                int right = 0;
                int down = 0;
                if (j > 0) {
                    right = cur[j - 1];
                }
                if (i > 0) {
                    down = prev[j];
                }
                cur[j] = right + down;
            }
        }
        prev = cur;
    }
    return cur[n - 1];
}
int main(){
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
    cout << uniquePathsII(m, n, grid);
    return 0;
}