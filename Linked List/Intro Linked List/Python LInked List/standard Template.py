class Node:
    def __init__(self, value, next_node):
        self.data = value
        self.next = next_node

n = Node(7, None)
print(f"Node n -> data = {n.data}, next = {n.next}")