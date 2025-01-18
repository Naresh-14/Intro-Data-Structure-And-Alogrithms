#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v = {10,20,30,40,50};
  
  // 1. initialize a vector iterator
  vector <int> ::iterator rIt = v.begin();
  vector <int> ::iterator rEndIt = v.end();
  
  //2.using rbegin() and rend() for reverse iterator
  cout << "First element using reverse iterator: " << *rIt  <<endl;
  cout << "Last element using reverse iterator: " << *(--rEndIt)  << endl;
  return 0;
}