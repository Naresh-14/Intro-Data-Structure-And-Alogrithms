#include <bits/stdc++.h>
using namespace std;
int frogJump(int i, int height[]){
    if(i == 0){
        return 0;
    }
    if(i == 1){
        return abs(height[1] - height[0]);
    }
    int s1 = abs(height[i] - height[i-1]) + frogJump(i-1, height);
    int s2 = abs(height[i] - height[i-2]) + frogJump(i-2, height);
    return min(s1, s2);
}
int main() {
    int n;
    cin >> n;
    int height[n];
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    cout << frogJump(n-1, height);
    return 0;
}