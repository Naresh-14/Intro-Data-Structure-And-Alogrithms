#include<bits/stdc++.h>
using namespace std;
int frogJumpII(int height[], int k, int n) {
    if (n == 0)
        return 0;
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i <= n-1; i++) {
        int min_energy = INT_MAX;
        int energy;
        for (int j = 1; j <= k; j++) {
            if ((i - j) >= 0) {
                energy = abs(height[i] - height[i - j]) + dp[i - j];
                min_energy = min(energy, min_energy);
            }
        }
        dp[i] = min_energy;
    }
    return dp[n - 1];
}
int main() {
    int n, k;
    cin >> n >> k;
    int height[n];
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    cout << frogJumpII(height, k, n);
    return 0;
}