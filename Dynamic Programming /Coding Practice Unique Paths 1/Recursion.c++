#include<bits/stdc++.h>
using namespace std;
int uniquePaths(int i, int j){
    if(i == 0 || j == 0){
        return 1;
    }
    int right = uniquePaths(i, j-1);
    int down = uniquePaths(i-1, j);
    return right + down;
}
int main() {
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m-1, n-1);
    return 0;
}