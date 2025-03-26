#include <bits/stdc++.h>
using namespace std;
bool subset_sum(int n, int k, int arr[]) {
    vector<vector<int>> dp(n, vector<int>(k+1));
    
    for(int i=0; i<n; i++) dp[i][0] = 1;
    
    for(int total = 1; total <= k ; total++)
    {
        if( total == arr[0]) 
            dp[0] [total] = 1;
        else
            dp[0][total] = 0;
    }

    for(int i=1; i<n; i++)
    {
        for(int total = 1; total<=k; total++)
        {
            bool not_pick = dp[i-1][total];
            bool pick ;
            if(arr[i] > total)
                pick = 0;
            else
                pick = dp[i-1][total-arr[i]];
            dp[i][total] = pick || not_pick ;
        }
    }
return dp[n-1][k];
}

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<subset_sum(n,k,arr);
    
    return 0;
    
}