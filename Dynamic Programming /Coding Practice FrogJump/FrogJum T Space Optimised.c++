#include <bits/stdc++.h>
using namespace std;
int frogJump(int i, vector<int> height){
    if(i == 0){
        return 0;
    }
    if(i == 1){
        return abs(height[1] - height[0]);
    }
    int prior_2 = 0;
    int prior_1 = abs(height[1] - height[0]);
    int cur;
    for(int j = 2; j <= i; j++){
        int s1 = abs(height[j] - height[j-1]) + prior_1;
        int s2 = abs(height[j] - height[j-2]) + prior_2;
        cur = min(s1, s2);
        prior_2 = prior_1;
        prior_1 = cur;
    }
    return cur;
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