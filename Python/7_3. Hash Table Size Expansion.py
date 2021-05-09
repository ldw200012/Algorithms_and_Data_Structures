# Hash Table class
class HashTable:
	def __init__(self, n):
		self.n = n
		self.hash_table = list([0 for i in range(n)])

	def hash_function(self, key):
		return key % self.n

	def insert(self, key, value):
		hash_value = self.hash_function(hash(key))
		self.hash_table[hash_value] = value

	def read(self, key):
		hash_value = self.hash_function(hash(key))
		return self.hash_table[hash_value]

	def print(self):
		print(self.hash_table)

ht = HashTable(13)

ht.insert(1, 'a')
ht.print()
ht.insert('name', 'kang')
ht.print()
ht.insert(2, 'b')
ht.print()
ht.insert(3, 'c')
ht.print()
ht.insert(4, 'd')
ht.print()

print(ht.read(2))