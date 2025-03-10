#include <bits/stdc++.h>
using namespace std;
int f(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    int prior_2 = 1;
    int prior_1 = 1;
    int cur = 0;
    for (int i = 2; i <= n; i++){
        cur = prior_1 + prior_2;
        prior_2 = prior_1;
        prior_1 = cur;
    }
    return cur;
}
int main() {
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}