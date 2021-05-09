# n elements in Linked List

A = original Linked List
n = number of elements in A

for i in range(1, n):
	temp = A.head
	A.head = A.head.next
	A.head.next = temp

	if i == 1:
		A.head.next.next = None

# In this Algorithm, we do not need to use any auxiliary storage (except using 'temp' as auxiliary variable)
# We can reverse the Linked List only by changing the direction of pointers in between Stack Nodes