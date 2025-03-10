#include<bits/stdc++.h>
using namespace std;
int frogJumpII(int i, int k, int height[]) {
    if (i == 0)
        return 0;
    int min_energy = INT_MAX;
    for (int j = 1; j <= k; ++j) {
        if ((i - j) >= 0) {
            int energy = abs(height[i] - height[i - j]) + frogJumpII(i - j, k, height);
            min_energy = min(energy, min_energy);
        }
    }
    return min_energy;
}
int main() {
    int n, k;
    cin >> n >> k;
    int height[n];
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    cout << frogJumpII(n-1, k, height);
    return 0;
}