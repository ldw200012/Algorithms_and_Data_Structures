class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

# LinkedList class
class LinkedList():
	def __init__(self):
		self.head = None

	def add(self, data):
		new_node = Node(data)
		if not self.head:
			self.head = new_node
		else:
			node = self.head
			while node.next:
				node = node.next
			node.next = new_node

	def delete(self, data):
		node = self.head
		if node.data == data:
			self.head = node.next
			del node
		else:
			while node.next:
				next_node = node.next
				if next_node.data == data:
					node.next = next_node.next
					del next_node
				else:
					node = node.next

	def find(self, data):
		node = self.head
		while node:
			if node.data == data:
				return node
			else:
				node = node.next

	def print(self):
		node = self.head
		while node:
			print(node.data)
			node = node.next

ll = LinkedList()

ll.add(1)
ll.add(2)
ll.add(3)
ll.print()

ll.delete(2)
ll.print()

ll.delete(1)
ll.print()

ll.delete(3)
ll.print()

print(ll.head)