#include <bits/stdc++.h>
using namespace std;
int subset_sum(int n, int k, int arr[]) {
    vector<vector<int>> dp(n, vector<int>(k + 1));
    for (int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    for (int total = 1; total <= k; total++) {
        if (total == arr[0]){
            dp[0][total] = 1;
        }
        else{
            dp[0][total] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int total = 1; total <= k; total++) {
            bool not_pick = dp[i - 1][total];
            bool pick;
            if (arr[i] > total){
                pick = 0;
            }
            else{
                pick = dp[i - 1][total - arr[i]];
            }
            dp[i][total] = pick || not_pick;
        }
    }
    int ans = INT_MAX;
    for(int x = 0; x <= k; x++){
        if(dp[n-1][x]){
            ans = min(ans, abs(2 * x - k));
        }
    }
    return ans;
}
int partition(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return subset_sum(n, sum, arr);
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << partition(arr, n);
    return 0;
}