import math


def print_array(array):
    for temp in range(0, len(array)):
        print(array[temp])


def insertion_sort(arr, first_index):
    if len(arr) == 1:
        return 0
    for t in range(first_index + 1, len(arr)):
        temp = arr[t]
        j = 0
        k = 0
        for j in reversed(range(first_index, t)):
            if arr[j] > temp:
                arr[j+1] = arr[j]
                k = j
            else:
                k = j+1
                break
        arr[k] = temp

if __name__ == "__main__":
    A = [0, 0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1]  # first 0 is default
    n = len(A) - 1  # number of elements in A except the first default one, 0
    B = []
    C = []
    for i in range(0, n):
        B.append([])

    for i in range(1, n+1):
        # print(A[i], "to", math.floor(n*A[i]))
        B[int(math.floor(n*A[i]))].append(A[i])

    for i in range(0, n):
        insertion_sort(B[i], 0)

    num = 0
    for i in range(0, n):
        for j in range(0, len(B[i])):
            C.append(B[i][j])

    print_array(C)