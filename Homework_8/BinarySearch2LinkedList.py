# Suppose we have a BST named 'A'
# and make a Linked List


class Tree:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None


class Node:
    def __init__(self, key):
        self.key = key
        self.next = None


def tree_minimum(x):
    while x.left is not None:
        x = x.left
    return x
# O(h)


def tree_successor(x):
    if x.right is not None:
        return tree_minimum(x.right)
    y = x.parent
    while y is not None and x == y.right:
        x = y
        y = y.parent
    return y
# O(h)


root = Tree(15)

a = Tree(6)
root.left = a
a.parent = root

b = Tree(18)
root.right = b
b.parent = root

c = Tree(3)
a.left = c
c.parent = a

d = Tree(7)
a.right = d
d.parent = a

e = Tree(17)
b.left = e
e.parent = b

f = Tree(20)
b.right = f
f.parent = b

g = Tree(2)
c.left = g
g.parent = c

h = Tree(4)
c.right = h
h.parent = c

i = Tree(13)
d.right = i
i.parent = d

j = Tree(9)
i.left = j
j.parent = i

# Making into Linked List
currentTree = tree_minimum(root) # O(h)
head = Node(currentTree.key)
tail = head
for k in range(1, 11): # O(n-1)
    currentTree = tree_successor(currentTree) # O(h)
    tail.next = Node(currentTree.key)
    tail = tail.next

# Print out to check validity
while head is not None:
    print(head.key)
    head = head.next



