if __name__ == '__main__':
    A = list()  # Input  Array
    A_sum = list()
    B = list()  # Result Array
    temp = list()
    row_num = int(input("How many rows do you have ? >> "))

    # Get Triangular integer inputs
    # and put them into array
    for i in range(0, row_num):
        temp = list(map(int, input().split()))
        A.extend(temp)
        A_sum.extend(temp)

    # Sum up from below to top
    current_row = row_num - 1
    while current_row > 0:
        for i in range(int(((current_row)*(current_row-1))/2), int(((current_row+1)*(current_row))/2)):
            selected_int = max(A_sum[i+current_row], A_sum[i+current_row+1])
            A_sum[i] += selected_int
        current_row -= 1

    # Now we have our maximum sum value
    print(A_sum[0])

    # Find the corresponding elements current_row = 1
    idx = 0
    B.append(A[idx])
    for i in range(1, row_num):
        left_idx = idx + i
        right_idx = idx + i + 1
        if A_sum[left_idx] > A_sum[right_idx]:
            B.append(A[left_idx])
            idx = left_idx
        else:
            B.append(A[right_idx])
            idx = right_idx

    for i in range(0, len(B)):
        print(B[i], end=' ')
    print()

