INF = float('inf')


def find_meetup_city(adj_matrix, my_city, friend_city):
    # my_city is the starting node
    n = len(adj_matrix)
    visited = list()

    my_matrix = [[0 for col in range(3)] for row in range(n)]
    for i in range(n):
        my_matrix[i][0] = adj_matrix[i][0]
        my_matrix[i][1] = float('inf')  # shortest distance from my_city
        my_matrix[i][2] = 0

    visiting_city = my_city
    next_city = 0
    my_matrix[visiting_city][1] = 0
    while len(visited) != n:
        visited.append(visiting_city)

        min = float('inf')
        for i in range(0, n):
            if i not in visited:
                if my_matrix[i][1] > my_matrix[visiting_city][1] + adj_matrix[visiting_city][i]:
                    my_matrix[i][1] = my_matrix[visiting_city][1] + adj_matrix[visiting_city][i]
                    my_matrix[i][2] = visiting_city

                if my_matrix[i][1] < min and my_matrix[i][0] != visiting_city:
                    min = my_matrix[i][1]
                    next_city = i

        visiting_city = next_city

    print("Visited Cities in order : ", end=' ')
    for i in range(0, len(visited)):
        print(visited[i], end=' ')
    print()

    # Now I need to back-track the path
    global path
    path = list()

    current_city = friend_city
    while current_city != my_city:
        path.insert(0, current_city)
        current_city = my_matrix[current_city][2]
    path.insert(0, current_city)

    # Now I find the place in the middle, which is m
    tsum_u = 0
    tsum_v = 0

    it_one = 0
    it_sec = len(path)-1
    for i in range(0, len(path)-1):
        if tsum_u <= tsum_v:
            tsum_u += adj_matrix[path[it_one]][path[it_one+1]]
            dest_u = path[it_one+1]
            it_one += 1
        else:
            tsum_v += adj_matrix[path[it_sec-1]][path[it_sec]]
            dest_v = path[it_sec-1]
            it_sec -= 1

    print("Total time (", my_city, ", ", friend_city, ") : ", my_matrix[friend_city][1])

    print("Path (", my_city, ", ", friend_city, ") : ", end=' ')
    for i in range(0, len(path)):
        print(path[i], end=' ')
    print()

    return dest_u


if __name__ == '__main__':

    my_city = 0
    friend_city = 2

    adj_matrix = [[0, 3, 6, 8, 7],
                  [3, 0, 2, 4, 8],
                  [6, 2, 0, 5, 5],
                  [8, 4, 5, 0, 2],
                  [7, 8, 5, 2, 0]]
    print("Ideal Meet_Up City : ", find_meetup_city(adj_matrix, my_city, friend_city))

    my_city2 = 4
    friend_city2 = 5

    adj_matrix2 = [[0,   7,   INF, INF, 3,   10,  INF],
                   [7,   0,   4,   10,  2,   6,   INF],
                   [INF, 4,   0,   2,   INF, INF, INF],
                   [INF, 10,  2,   0,   11,  9,   4  ],
                   [3,   2,   INF, 11,  0,   INF, 5  ],
                   [10,  6,   INF, 9,   INF, 0,   INF],
                   [INF, INF, INF, 4,   5,   INF, 0  ]]
    print("Ideal Meet_Up City : ", find_meetup_city(adj_matrix2, my_city2, friend_city2))

