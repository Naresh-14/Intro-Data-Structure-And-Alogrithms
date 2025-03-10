#include <bits/stdc++.h>
using namespace std;
int f(int i)
{
    if(i==1) return 1;
    if(i==0) return 1;
    
    int left = f(i-1);
    int right = f(i-2);
    
    return left+right;
}
int main() {
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}