#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v;
  v.push_back(10);
  v.emplace_back(20);
  cout << v[0]<< " " << v[1] << endl;
  return 0;
}