#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
    public:
        Node(int value, Node* address){
            data = value;
            next = address;
        }
    public:
        Node(int value){
            data = value;
            next = nullptr;
        }
    public:
        Node(){
            data = 0;
            next = nullptr;
        }
};
int main() {
    Node *p1 = new Node(5, nullptr);
    Node *p2 = new Node(7);
    Node *p3 = new Node();
    cout << p1->data << endl; // 5
    cout << p2->data << endl; // 7
    cout << p3->data << endl; // 0
    return 0;
}