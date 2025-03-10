#include <bits/stdc++.h>
using namespace std;
int frogJump(int i, int height[], vector<int> &dp){
    if(i == 0){
        return 0;
    }
    if(i == 1){
        return abs(height[1] - height[0]);
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int s1 = abs(height[i] - height[i-1]) + frogJump(i-1, height, dp);
    int s2 = abs(height[i] - height[i-2]) + frogJump(i-2, height, dp);
    dp[i] = min(s1, s2);
    return dp[i];
}
int main() {
    int n;
    cin >> n;
    int height[n];
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    vector<int> dp(n, -1);
    cout << frogJump(n-1, height, dp);
    return 0;
}