#include<bits/stdc++.h>
using namespace std;

int main() {
  pair<int, double> myPair = {42, 3.14159};  // pair with int and double data types
  pair<int, char> myPair1 = {0, 'a'};  // pair with int and char data types
  pair<int, string> myPair2 = {21, "Hello World"};  // pair with int and string data types

    // Printing the elements
    cout << "1st Pair First Element: " << myPair.first << ", 1st Pair Second Element: " << myPair.second << endl;
    cout << "2nd Pair First Element: " << myPair1.first << ", 2nd Pair Second Element: " << myPair1.second << endl;
    cout << "3rd Pair First Element: " << myPair2.first << ", 3rd Pair Second Element: " << myPair2.second << endl;
    
    // pair with multiple elements
    pair<int, pair<int, int>> nestedPair = {0, {10, 20}};
    cout << "First: " << nestedPair.first << ", Second 1: " << nestedPair.second.first << ", Second 2: " << nestedPair.second.second << endl;
    
     // array of pairs
    pair<int, string> pairs[] = {{1, "One"},{2, "Two"},{3, "Three"}};
    cout << "2nd Pair in Array: First Element: "<< pairs[1].first << " Second Element: " << pairs[1].second << endl;
    
  return 0;
}