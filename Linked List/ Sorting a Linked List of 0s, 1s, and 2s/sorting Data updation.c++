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


Node* array_to_LL(int arr[], int n){
    if(n == 0){
        return nullptr;
    }
    Node* head = new Node(arr[0]);
    Node* cur = head;
    for(int i=1; i<=n-1; i++)
    {
        Node* temp = new Node(arr[i]);
        cur->next = temp;
        cur = cur->next;
    }
    return head;
}
void print_LL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
}


Node* sortLL0s1s2s(Node* head){
    Node* temp = head;
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    while(temp != nullptr){
        if(temp->data == 0)
            count_0 += 1;
        else if(temp->data == 1)
            count_1 += 1;
        else if(temp->data == 2)
            count_2 += 1;
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        if(count_0){
            temp->data = 0;
            count_0 -= 1;
        }
        else if(count_1){
            temp->data = 1;
            count_1 -= 1;
        }
        else if(count_2){
            temp->data = 2;
            count_2 -= 1;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Node* head = array_to_LL(arr, n);
    head = sortLL0s1s2s(head);
    print_LL(head);
    return 0;
}
