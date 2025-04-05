class Node:
    def __init__(self,value,address=None):
        self.data = value 
        self.next = address 

def array_to_LL(arr):
    if n == 0:
        return None 
    
    head = Node(arr[0])
    cur = head 
    for i in range(1,len(arr)):
        temp = Node(arr[i])
        cur.next = temp
        cur = cur.next 
    return head

def print_LL(head):
    temp = head
    while temp != None:
        print(temp.data,end=" ")
        temp = temp.next

n = int(input())
arr = []
if n > 0:
    arr = list(map(int, input().split()))

head = array_to_LL(arr)
print_LL(head)