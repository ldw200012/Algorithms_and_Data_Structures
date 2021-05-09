import random

INF = float('inf')


def node_edge_matrix(number_maze):
    return_adj_matrix = [[INF for col in range(len(number_maze)**2)]for row in range(len(number_maze)**2)]

    n = len(number_maze)
    m = len(return_adj_matrix)
    for i in range(0, n):
        for j in range(0, n):
            key = number_maze[i][j]
            return_adj_matrix[(n * i) + j][(n * i) + j] = 0
            if 0 <= i+key < n:                                # Down
                return_adj_matrix[(n * i) + j][(n * (i + key)) + j] = 1
            if 0 <= i-key < n:                                # Up
                return_adj_matrix[(n * i) + j][(n * (i - key)) + j] = 1
            if 0 <= j+key < n:                                # Right
                return_adj_matrix[(n * i) + j][(n * i) + (j+key)] = 1
            if 0 <= j-key < n:                                # Left
                return_adj_matrix[(n * i) + j][(n * i) + (j-key)] = 1

    return return_adj_matrix


def number_maze_path(number_maze):
    adj_matrix = node_edge_matrix(number_maze)
    n = len(adj_matrix)
    start = 0
    target = n-1
    visited = list()

    my_matrix = [[0 for col in range(3)] for row in range(n)]
    for i in range(n):
        my_matrix[i][0] = adj_matrix[i][0]
        my_matrix[i][1] = INF
        my_matrix[i][2] = 0

    visiting_node = start
    next_node = 0
    my_matrix[visiting_node][1] = 0
    while True:
        visited.append(visiting_node)

        my_min = float('inf')
        for i in range(0, n):
            if i not in visited:
                if my_matrix[i][1] > my_matrix[visiting_node][1] + adj_matrix[visiting_node][i]:
                    my_matrix[i][1] = my_matrix[visiting_node][1] + adj_matrix[visiting_node][i]
                    my_matrix[i][2] = visiting_node

                if my_matrix[i][1] < my_min and my_matrix[i][0] != visiting_node:
                    my_min = my_matrix[i][1]
                    next_node = i

        if visiting_node == next_node:
            break
        else:
            visiting_node = next_node

    # print("Visited Tiles in order : ", end=' ')
    # for i in range(0, len(visited)):
    #     print(visited[i], end=' ')
    # print()

    # Now I need to back-track the path
    global path
    path = list()

    current_node = target
    while current_node != start:
        path.insert(0, current_node)
        current_node = my_matrix[current_node][2]
    path.insert(0, current_node)

    print("Path (", start, ", ", target, ") : ", end=' ')
    for i in range(0, len(path)):
        print(path[i], end=' ')
    print()

    if my_matrix[target][1] == INF:
        return -1
    else:
        return my_matrix[target][1]


class PuzzleBoard:
    def __init__(self, n):
        self.grid_num = n
        self.number_maze = [[0 for col in range(n)]for row in range(n)]
        for i in range(n):
            for j in range(n):
                temp = random.randrange(1, n)
                self.number_maze[i][j] = temp
        self.current_row = 0
        self.current_column = 0
        self.__adj_matrix = node_edge_matrix(self.number_maze)

    def make_move(self, direction):
        # 0 --> up
        # 1 --> right
        # 2 --> down
        # 3 --> left
        factor = self.number_maze[self.current_row][self.current_column]

        if direction == 0:
            if 0 <= (self.current_row - (1 * factor)):
                self.current_row -= (1 * factor)
                return True

        elif direction == 1:
            if (self.current_column + (1 * factor)) <= self.grid_num:
                self.current_column += (1 * factor)
                return True

        elif direction == 2:
            if (self.current_row + (1 * factor)) <= self.grid_num:
                self.current_row += (1 * factor)
                return True

        elif direction == 3:
            if 0 <= (self.current_column - (1 * factor)):
                self.current_column -= (1 * factor)
                return True

        return False


    def get_result(self):
        if self.current_row == n-1 and self.current_column == n-1:
            return True
        else:
            return False

    def __str__(self):
        temp_str = ""
        for i in range(self.grid_num):
            for j in range(self.grid_num):
                temp_str += str(self.number_maze[i][j])
                temp_str += " "
            temp_str += "\n"

        return temp_str

    def solve(self):
        return number_maze_path(self.number_maze)


if __name__ == '__main__':
    grid_size = 5                                 # Set grid size
    my_puzzle = PuzzleBoard(grid_size)

    n = len(my_puzzle.number_maze)
    print(my_puzzle)

    print("Starting from [0] ...\n0: UP\n1: RIGHT\n2: DOWN\n3: LEFT\n4: STOP and SOLVE")
    while True:
        current_idx = (grid_size*my_puzzle.current_row)+my_puzzle.current_column
        # print("\nCurrent Key =", current_idx)
        print("Current Position =", my_puzzle.current_row, my_puzzle.current_column)
        if current_idx == (n**2)-1:
            print("Puzzle Solved!")
            break
        user = int(input("Direction: "))
        if user == 4:
            print("Puzzle Solved!" if my_puzzle.get_result() else "Not Solved")
            break
        elif user < 0 or user > 4:
            print("Invalid Key")
            continue
        print("Valid Key" if my_puzzle.make_move(user) else "Invalid Key")

    print(my_puzzle.solve())
