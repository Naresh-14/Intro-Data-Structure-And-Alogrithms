#include <bits/stdc++.h>
using namespace std;
bool f(int i, int total, int n, int k, int arr[], vector<vector<int>> &dp)
{
    if(total == 0)
        return true;
    if(i == 0)
    {
        if( total == arr[0])
            return true;
        else
            return false;
    }
    
    bool not_pick = f(i-1, total, n, k, arr, dp);
    bool pick ;
    if(arr[i] > total) pick = false;
    else pick = f(i-1, total-arr[i], n, k, arr, dp);
    return pick || not_pick;
}
bool subset_sum(int n, int k, int arr[])
{
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1, k,n,k, arr,dp);
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