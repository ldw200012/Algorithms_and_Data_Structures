def print_array(array):
    for temp in range(0, len(array)):
        print(array[temp])


def insertion_sort(arr, n3, k3):
    for i in range(1, n3):
        key = arr[i]

        j = i - 1
        while j >= 0:
            if k3 == 0:
                if key[k3] < arr[j][k3]:
                    arr[j + 1] = arr[j]
                    j -= 1
                elif key[k3] == arr[j][k3] and len(key) < len(arr[j]):
                    arr[j + 1] = arr[j]
                    j -= 1
                else:
                    break
            else:
                if arr[j][k3 - 1] == key[k3 - 1]:
                    if key[k3] < arr[j][k3]:
                        arr[j + 1] = arr[j]
                        j -= 1
                    elif key[k3] == arr[j][k3] and len(key) < len(arr[j]):
                        arr[j + 1] = arr[j]
                        j -= 1
                    else:
                        break
                else:
                    break

        arr[j + 1] = key


def radix_sort(array, n2, k2):
    for i in range(0, k2):
        insertion_sort(A, n2, i)


A = []
n = 0
k = 1000

while True:
    my_word = raw_input("Word Input >> ")
    if my_word == "exit":
        break
    A.append(my_word)
    if len(my_word) < k:
        k = len(my_word)
    n += 1

print("Input: ")
print_array(A)
radix_sort(A, n, k)
print("Result: ")
print_array(A)
