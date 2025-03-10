#include <bits/stdc++.h>
using namespace std;
int max_sum_non_adjacent(int n, int arr[]){
    int p2 = arr[0];
    if(n == 1)
        return p2;
    int p1 = max(arr[0], arr[1]);
    for(int i = 2; i <= n-1; i++){
        int pick = arr[i] + p2;
        int not_pick = p1;
        int cur = max(pick, not_pick);
        p2 = p1;
        p1 = cur;
    }
    return p1;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int arr_1[n-1], arr_2[n-1];
    for(int i = 0; i <= n-2; i++){
        arr_1[i] = arr[i];
        arr_2[i] = arr[i+1];
    }
    int x = max_sum_non_adjacent(n-1, arr_1);
    int y = max_sum_non_adjacent(n-1, arr_2);
    cout << max(x, y);
    return 0;
}