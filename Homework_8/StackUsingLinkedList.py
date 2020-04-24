class StackNode:
    def __init__(self, data):
        self.value = data
        self.address = None


class Stack:
    def __init__(self):
        self.size = -1
        self.currentSize = -1
        self.firstNode = None

    def set_size(self, size):
        self.size = size
        self.currentSize = 0

    def push(self, x):
        if self.size == -1:
            print("The Stack is not set")
            return False

        if self.currentSize >= self.size:
            print("Stack Overflow")
            return False

        new_node = StackNode(x)
        new_node.address = self.firstNode
        self.firstNode = new_node

        self.currentSize += 1

    def pop(self):
        if self.size == -1:
            print("The Stack is not set")
            return False

        if self.currentSize < 1:
            print("Stack Underflow")
            return False

        temp = self.firstNode
        self.firstNode = self.firstNode.address
        self.currentSize -= 1

        return temp

    def is_empty(self):
        if self.size == -1:
            print("The Stack is not set")
            return False

        if self.currentSize == 0:
            return True
        else:
            return False


# Queue Behavior
class Queue:
    def __init__(self):
        self.stack1 = Stack()
        self.stack2 = Stack()

    def set_size(self, size):
        self.stack1.set_size(size)
        self.stack2.set_size(size)

    def push(self, x):
        self.stack1.push(x)

    def de_queue(self):
        for k in range(0, self.stack2.currentSize):
            self.stack2.pop()

    def set_queue(self):
        self.de_queue()
        for k in range(0, self.stack1.currentSize):
            self.stack2.push(self.stack1.pop().value)

    def pop(self):
        temp = self.stack2.pop()
        if temp:
            print(temp.value)
        return temp


Q = Queue()
Q.set_size(5)
Q.push(1)
Q.push(2)
Q.push(3)
Q.push(4)
Q.push(5)
Q.push(6)
Q.set_queue()
Q.pop()
Q.pop()
Q.pop()
Q.pop()

