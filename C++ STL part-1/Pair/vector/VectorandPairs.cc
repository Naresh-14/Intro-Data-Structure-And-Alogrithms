#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<pair<int,int>> pairs;
  pairs.push_back({10,20});
  pairs.emplace_back(30,40);
  cout << "Pair 1: " << pairs[0].first << " " << pairs[0].second << endl;
  cout << "Pair 2: " << pairs[1].first << " " << pairs[1].second << endl;
  return 0;
}