#include<bits/stdc++.h>
using namespace std;
int frogJumpII(int i, int k, int height[], vector<int> &dp) {
    if (i == 0)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int min_energy = INT_MAX;
    for (int j = 1; j <= k; ++j) {
        if ((i - j) >= 0) {
            int energy = abs(height[i] - height[i - j]) + frogJumpII(i - j, k, height, dp);
            min_energy = min(energy, min_energy);
        }
    }
    return dp[i] = min_energy;
}
int main() {
    int n, k;
    cin >> n >> k;
    int height[n];
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    vector<int> dp(n, -1);
    cout << frogJumpII(n-1, k, height, dp);
    return 0;
}