def print_array(array):
    for temp in range(0, len(array)):
        print(array[temp])


def find_max(array):
    max_ = array[0]
    for count in range(1, len(array)):
        if array[count] > max_:
            max_ = array[count]
    return max_


def find_max_exponent(a):
    count = 0
    while a // 10 != 0:
        a //= 10
        count += 1
    return count


def insertion_sort(arr, bit):
    for i in range(1, len(arr)):
        key = arr[i]

        j = i - 1
        while j >= 0 and (arr[j] // (bit * 10)) % 10 == (key // (bit * 10)) % 10:
            if (key//bit) % 10 < (arr[j]//bit) % 10:
                arr[j + 1] = arr[j]
                j -= 1
            else:
                break
        arr[j + 1] = key


def radix_sort(A):
    m = find_max(A)
    ex = find_max_exponent(m)
    while ex >= 0:
        insertion_sort(A, 10 ** ex)
        ex -= 1


A = [321, 100, 1239, 234, 263, 297, 203, 409]
radix_sort(A)






print_array(A)




