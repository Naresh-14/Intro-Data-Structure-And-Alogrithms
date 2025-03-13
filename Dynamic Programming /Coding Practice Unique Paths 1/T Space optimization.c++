#include<bits/stdc++.h>
using namespace std;
int uniquePaths(int m, int n){
    int prior[n];
    int cur[n];
    cur[0] = 1;
    for(int i = 0; i < n; i++){
        prior[i] = 1;
    }
    for (int i = 1; i <= m-1; i++){
        for(int j = 1; j <= n-1; j++){
            cur[j] = cur[j-1] + prior[j];
        }
        for(int j = 1; j <= n-1; j++){
            prior[j] = cur[j];
        }
    }
    return prior[n-1];
}
int main() {
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n);
    return 0;
}