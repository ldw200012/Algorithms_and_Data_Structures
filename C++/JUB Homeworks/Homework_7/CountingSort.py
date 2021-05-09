# 1 for i := 1 to k do
# 2 C [ i ] := 0
# 3 for j := 1 to n do
# 4 C [ A [ j ]] := C [ A [ j ]] + 1
# 5 // C[i] = |{ key = i}|
# 6 for i := 2 to k do
# 7 C [ i ] := C [ i ] + C [ i - 1]
# 8 // C[i] = |{ key <= i }|
# 9 for j := n down to 1 do
# 10 B [ C [ A [ j ]]] = A [ j ]
# 11 C [ A [ j ]] = C [ A [ j ]] - 1


def print_array(a):
    for temp in range(1, len(a)):
        print(a[temp])


n = 7  # number of elements in array A (except the first default element, 0)
k = 9  # A[j] in range [1, k] where j > 0
A = [0, 9, 1, 6, 7, 6, 2, 1]
B = [0]
C = [0]

for i in range(1, k+1):
    C.append(0)

for j in range(1, n+1):
    B.append(0)
    C[A[j]] += 1

for i in range(2, k+1):
    C[i] = C[i] + C[i-1]

for j in range(n, 0, -1):
    B[C[A[j]]] = A[j]
    C[A[j]] -= 1

print("Input: ")
print_array(A)
print("Result: ")
print_array(B)



