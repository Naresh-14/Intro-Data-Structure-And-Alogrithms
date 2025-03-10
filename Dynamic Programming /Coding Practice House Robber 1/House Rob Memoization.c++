#include <bits/stdc++.h>
using namespace std;
int f(int i, int arr[], vector<int>& dp)
{
    if( i == 0) 
        return arr[0];
        
    if( i == 1)
        return max( arr[0], arr[1]);
        
    if(dp[i] != -1)
        return dp[i];
        
    int pick = arr[i] + f(i-2, arr, dp);
    
    int not_pick = f(i-1, arr, dp);
    
    return dp[i] = max(pick, not_pick);
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> dp(n,-1);
    
    cout << f(n-1,arr,dp);
    
    return 0;
}