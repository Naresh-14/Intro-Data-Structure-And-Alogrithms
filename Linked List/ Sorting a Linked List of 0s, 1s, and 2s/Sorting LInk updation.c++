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
    Node* prev_0 = nullptr;
    Node* prev_1 = nullptr;
    Node* prev_2 = nullptr;
    Node* first_0 = nullptr;
    Node* first_1 = nullptr;
    Node* first_2 = nullptr;
    while(temp != nullptr){
        if(temp->data == 0){
            if(prev_0 == nullptr){
                first_0 = temp;
            }
            else{
                prev_0->next = temp;
            }
            prev_0 = temp;
        }
        else if(temp->data == 1){
            if(prev_1 == nullptr){
                first_1 = temp;
            }
            else{
                prev_1->next = temp;
            }
            prev_1 = temp;
        }
        else if(temp->data == 2){
            if(prev_2 == nullptr){
                first_2 = temp;
            }
            else{
                prev_2->next = temp;
            }
            prev_2 = temp;
        }
        temp = temp->next;
    }
    if(prev_0 != nullptr){
        if(first_1 != nullptr){
            prev_0->next = first_1;
        }
        else{
            prev_0->next = first_2;
        }
    }
    if(prev_1 != nullptr){
        prev_1->next = first_2;
    }
    if(prev_2 != nullptr){
        prev_2->next = nullptr;
    }
    if(first_0 != nullptr){
        return first_0;
    }
    if(first_1 != nullptr){
        return first_1;
    }
    return first_2;
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