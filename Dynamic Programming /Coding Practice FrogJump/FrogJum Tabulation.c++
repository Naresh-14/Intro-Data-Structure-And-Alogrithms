#include <bits/stdc++.h>
using namespace std;
int frogJump(int i, vector<int> height){
    if(i == 0){
        return 0;
    }
    if(i == 1){
        return abs(height[1] - height[0]);
    }
    int n = height.size();
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);
    for(int j = 2; j <= i; j++){
        int s1 = abs(height[j] - height[j-1]) + dp[j-1];
        int s2 = abs(height[j] - height[j-2]) + dp[j-2];
        dp[j] = min(s1, s2);
    }
    return dp[i];
}
int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    cout << frogJump(n-1, height);
    return 0;
}