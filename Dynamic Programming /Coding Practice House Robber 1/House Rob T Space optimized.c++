#include <bits/stdc++.h>
using namespace std;
int f(int n, int arr[])
{
    int p2 = arr[0];
    
    if(n == 1)
        return p2;
        
    int p1 = max(arr[0], arr[1]);
    
    for(int i=2; i<=n-1; i++)
    {
        int pick = arr[i] + p2;
        int not_pick = p1;
        int cur = max(pick, not_pick);
        p2 = p1;
        p1 = cur;
    }
    
    return p1;
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