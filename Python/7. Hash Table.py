import hashlib

data_1 = 'test'.encode()
hash_obj = hashlib.sha1() # or sha256()
hash_obj.update(data_1)
hex_dig = hash_obj.hexdigest()
print(hex_dig)

data_2 = "Hello World".encode()
hash_obj = hashlib.sha1() # or sha256()
hash_obj.update(data_2)
hex_dig = hash_obj.hexdigest()
print(hex_dig)

# Hash Table class
class HashTable:
	def __init__(self):
		self.hash_table = list([0 for i in range(8)])

	def hash_function(self, key):
		return key % 8

	def insert(self, key, value):
		hash_value = self.hash_function(hash(key))
		self.hash_table[hash_value] = value

	def read(self, key):
		hash_value = self.hash_function(hash(key))
		return self.hash_table[hash_value]

	def print(self):
		print(self.hash_table)

ht = HashTable()

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