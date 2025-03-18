#include <bits/stdc++.h>
using namespace std;
int minimum_sum(vector<vector<int>>& triangle, int n){
    vector<int> prev(n);
    vector<int> cur(n);
    for(int j=0; j<=n-1; j++)
    {
        prev[j] = triangle[n-1][j];
    }
    

    for(int i=n-2;i>=0; i--)
    {
        for(int j=0; j<=i; j++)
        {
            int down = triangle[i][j] + prev[j];
            int diagonal = triangle[i][j] + prev[j+1];
            cur[j] = min (down, diagonal) ;
        }
        prev = cur;
    }
    return prev[0];
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