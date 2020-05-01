
def set_cp_array(A, B):
    cp = 1
    B.append(cp)
    for i in range(0, len(A)-1):
        if A[i] < A[i+1]:
            cp += 1
        B.append(cp)


def set_longest_ordered_array(A, B, C):
    set_cp_array(A, B)
    to_append = A[0]
    for i in range(1, len(B)):
        if B[i-1] == B[i]:
            if A[i-1] < A[i]:
                to_append = A[i-1]
            else:
                to_append = A[i]
        else:  # where B[temp] < B[i]
            C.append(to_append)
            to_append = A[i]
    if to_append > C[len(C)-1]:
        C.append(to_append)


if __name__ == '__main__':
    A = [8, 3, 6, 50, 10, 8, 100, 30, 60, 40, 80]
    B = list()
    C = list()

    set_longest_ordered_array(A, B, C)

    # Check by print
    for i in range(0, len(C)):
        print(C[i], end=' ')


