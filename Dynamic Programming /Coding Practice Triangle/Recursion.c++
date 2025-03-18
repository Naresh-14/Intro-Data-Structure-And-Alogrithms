#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>> &dp) 
{
    if(i== n-1)
        return triangle[n-1][j];

        
    int down = triangle[i][j] + f(i+1,j,triangle,n,dp);
    int diagonal = triangle[i][j] + f(i+1,j+1, triangle,n,dp);
    
    return min(down, diagonal) ;
}

int minimum_sum(vector<vector<int>>& triangle, int n){
    
    vector<vector<int>> dp(n,vector<int>(n,-1)); 
    return f(0,0, triangle, n, dp);
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