# Array Initialization
array_1D = [1,2,3,4,5]
array_2D = [[1,2,3],[4,5,6],[7,8,9]]

# Array Element Access
print(array_1D[3])
print(array_2D[1][0])

# Application
array_str_1D = "Hello World"
array_str_2D = ["Hello", "World"]

def find_alphabet(dataset, alphabet): # Restricted to 2D array
	count = 0
	for data in dataset:
		for i in range(len(data)):
			if data[i] == alphabet:
				count += 1
	print(count, " Elements Found")

find_alphabet(array_str_1D, 'l')
find_alphabet(array_str_2D, 'l')