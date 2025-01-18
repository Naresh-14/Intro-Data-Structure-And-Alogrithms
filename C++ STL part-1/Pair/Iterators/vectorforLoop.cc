#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v = {10,20,30,40};
  cout << "using a for loop:" << endl;
  for (vector<int>::iterator it = v.begin(); it != v.end(); it ++){
      cout << *it << " ";
  }
  cout << endl;
  cout << "using auto with iterators:" << endl;
  for (auto it = v.begin(); it != v.end();it++){
      cout <<*it <<" ";
  }
  cout << endl;
  
  cout << "using a range-based for loop: "<< endl;
  for (int k:v){
      cout << k << " ";
  }
  cout << endl;
  cout << "using auto with range-based for loop:" << endl;
  for (auto k:v){
      cout << k << " ";
  }
  cout << endl;
  return 0;
}
