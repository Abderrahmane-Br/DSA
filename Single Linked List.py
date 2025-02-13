class SLL:
    def __init__(self):
        self.head=None
    
    def traverse(self):
        if(self.head == None):
            print('empty')
        else:
            curr = self.head
            while(curr != None):
                print(curr.data)
                curr = curr.next

    def add(self, node):
        if(self.head == None):
            self.head = node
        else:
            curr = self.head
            while(curr.next != None):
                curr = curr.next
            curr.next = node
    
    def rem_rec(self, curr):
        if(curr.next == None):
            return 
        else:
            if(curr.data >= curr.next.data):
                curr.next = curr.next.next
                return self.rem_rec(curr)
            return self.rem_rec(curr.next)

class Node:
    def __init__(self, data, next=None):
        self.data=data
        self.next=next


llist= SLL()

llist.add(Node(1))
llist.add(Node(2))
llist.add(Node(2))
llist.add(Node(3))
llist.add(Node(1))
llist.add(Node(4))
llist.add(Node(4))
llist.traverse()
llist.rem_rec(llist.head)
print('\nafter removal \n')
llist.traverse()

