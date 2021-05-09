import queue

priority_queue = queue.PriorityQueue()

priority_queue.put((10, 1))
priority_queue.put((5, 2))
priority_queue.put((15, 3))

print(priority_queue.get())
print(priority_queue.get())

# PriorityQueue class
class PriorityQueue:
	def __init__(self):
		self.my_list = list()

	def push(self, data):
		self.my_list.append(data)
		self.my_list.sort(key = lambda x: x[0])

	def pop(self):
		return self.my_list.pop(0)

	def qsize(self):
		return len(self.my_list)

my_priority_queue = PriorityQueue()

my_priority_queue.push((3, 0.1))
my_priority_queue.push((1, 0.25))
my_priority_queue.push((2, 0.4))

print(my_priority_queue.pop())
print(my_priority_queue.qsize())