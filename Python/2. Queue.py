import queue

# FIFO Queue
myq = queue.Queue()

myq.put(1)
myq.put(2)
myq.put(3)

print(myq.get())
print(myq.get())