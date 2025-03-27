#include <bits/stdc++.h>
using namespace std;

bool subset_sum(int n, int k, int arr[]) {
    vector<int> prev(k+1);
    vector<int> cur(k+1);
    prev[0] = 1;
    cur[0] = 1;

    for(int total = 1; total <= k; total++)
    {
        if( total == arr[0]) prev [total] = 1;
        else prev[total] = 0;
    }


    for(int i=1; i<n; i++)
    {
        for(int total = 1; total<=k; total++)
        {
            bool not_pick = prev [total];
            bool pick ;
            if(arr[i] > total) pick = 0;
            else pick = prev [total-arr[i]];
            cur[total] = pick || not_pick ;
        }
        prev = cur;
    }
    return cur[k];
}

bool partition(int n, int arr[]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    if (sum % 2 == 1) {
        return false;
    }
    
    return subset_sum(n, sum / 2, arr);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<partition(n,arr);
    
    return 0;
    
}