import queue

# LIFO Queue (= Stack)
stack = queue.LifoQueue()

stack.put(1)
stack.put(2)
stack.put(3)

print(stack.get())
print(stack.get())

# list in python (= Stack)
list_stack = list()
list_stack.append(1)
list_stack.append(2)

print(list_stack.pop())

# ListStack class (= Stack)
class Stack:
	def __init__(self):
		self.my_list = list()

	def push(self, data):
		self.my_list.append(data)

	def pop(self):
		return self.my_list.pop()

class_stack = Stack()
class_stack.push(1)
class_stack.push(8)
print(class_stack.pop())