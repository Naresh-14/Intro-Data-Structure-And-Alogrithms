#include <bits/stdc++.h>
using namespace std;


int f(int i, int sport, vector<vector<int>> &points )
{
    if(i < 0)
        return 0;
    int left = f(i-1, (sport+1)%3, points);
    int right = f(i-1, (sport+2)%3, points);
    int ans = points[i][sport] + max( left, right) ;
    return ans;
}

int training(int n, vector<vector<int>> &points )
{
    int a = f(n-1, 0, points);
    int b = f(n-1, 1, points); 
    int c = f(n-1, 2, points);
    return max( max(a, b), c);
}



int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>points[i][j];
        }
    }
    cout<<training(n,points);
    return 0;
}