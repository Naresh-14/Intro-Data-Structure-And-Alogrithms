
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* array_to_LL(int arr[], int n){
    if(n == 0){
        return nullptr;
    }
    Node* head = new Node(arr[0]);
    Node* cur = head;
    for(int i=1; i<=n-1; i++){
        Node* temp = new Node(arr[i]);
        cur->next = temp;
        cur = cur->next;
    }
    return head;
}
void printLL(Node *head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
Node* delete_tail(Node *head){
    if (head == nullptr)
        return head;
    if (head->next == nullptr){
        Node *temp = head;
        delete temp;
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next != nullptr){
        temp = temp->next;
    }
    Node *n = temp->next;
    temp->next = nullptr;
    delete n;
    return head;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Node* head = array_to_LL(arr, n);
    head = delete_tail(head);
    printLL(head);
    return 0;
}