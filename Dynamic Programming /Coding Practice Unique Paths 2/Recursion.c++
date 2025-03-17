#include<bits/stdc++.h>
using namespace std;
int uniquePathsII(int i, int j, vector<vector<int>> &grid){
    if(i < 0 || j < 0){
        return 0;
    }
    if(grid[i][j] == -1){
        return 0;
    }
    if(i == 0 && j == 0){
        return 1;
    }
    int right = uniquePathsII(i, j-1, grid);
    int down = uniquePathsII(i-1, j, grid);
    return right + down;
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
    cout << uniquePathsII(m-1, n-1, grid);
    return 0;
}