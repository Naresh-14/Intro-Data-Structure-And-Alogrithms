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
};
int main() {
    Node n = Node(7, nullptr);
    Node* p = &n;
    cout << "Accessing Values using node n - data = " << n.data << ", next = " << n.next << endl;
    cout << "Accessing Values using pointer p - data = " << p->data << ", next = " << p->next << endl;
    return 0;
}