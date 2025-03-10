#include <bits/stdc++.h>
using namespace std;
int f(int n, int arr[])
{
    vector<int> dp(n);
    dp[0] = arr[0];
    if(n == 1)
        return dp[0];
    dp[1] = max(arr[0], arr[1] ); 
    for(int i=2; i<=n-1; i++)
    {
        int pick = arr[i] + dp[i-2];
        int not_pick = dp[i-1];
        dp[i] = max(pick, not_pick);
    }
    return dp[n-1];
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout << f(n,arr);
    
    return 0;
}