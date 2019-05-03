class Node:
    #Constructor to initialize the node object
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    #Function to initialize head object
    def __init__(self):
        self.head = None
    
    #Function to reverse LinkedList
    def reverse(self):
        prev = None
        current = self.head
        while(current is not None):
            next = current.next
            current.next = prev
            prev = current
            current = next
        self.head = prev
    
    #Function to insert new node at the beggining
    def push(self, new_data):
        new_data = Node(new_data)
        new_data.next = self.head
        self.head = new_data
    
    # Utility function to print the linked LinkedList
    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data)
            temp = temp.next

# Driver program to test above functions
llist = LinkedList()
llist.push(10)
llist.push(20)
llist.push(30)
llist.push(40)
llist.push(50)

print("Given LinkedList")
llist.printList()

print("Revered LinkedList")
llist.reverse()
llist.printList()
        