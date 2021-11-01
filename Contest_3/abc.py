def conv_loc(loc):
    loc = int(loc) - 1
    x = loc // 6
    y = loc % 6
    return (x - 1, y - 1)

def find_status(grid):
    for row in range(4):
        blocked = 0
        filled = False
        for col in range(4):
            cell = grid[row][col]
            if cell == -1:
                blocked += 1
            if cell == 1:
                filled = True
                break
        if blocked == 3 and not filled:
            return ['r', row, col]
    
    for col in range(4):
        blocked = 0
        filled = False
        for row in range(4):
            cell = grid[row][col]
            if cell == -1:
                blocked += 1
            if cell == 1:
                filled = True
                break
        if blocked == 3 and not filled:
            return ['c', col, row]

def simplify_grid(grid):
    cells_used = []
    status = find_status()
    while status != []:
        n = status[1]
        if status[0] == 'r':
            row, col = status[1], status[2]
            grid[row][col] = 1
            for cols in range(4):
                if cols != col:
                    grid[row][col] = -1
            cells_used.append((row, col))
        if status[0] == 'c':
            row, col = status[2], status[1]
            grid[row][col] = 1
            for rows in range(4):
                if rows != row:
                    grid[row][col] = -1
            cells_used.append((row, col))
        status = find_status(grid)
    return cells_used

def update_grids(grid, cells_used):
    for cell in cells_used:
        x, y = cell[0], cell[1]
        grid[x][y] = -1

def update_start_letters(A_grid, B_grid, C_grid, start):
    grids = {'A' : A_grid, 'B' : B_grid, 'C' : C_grid}
    for letter in start:
        loc = letter[1]
        if loc[0] < 0:
            for row in range(4):
                if 
        elif loc[0] > 3:
        
        elif loc[1] < 0:
        
        else:

            

def find_final_grids(A_grid, B_grid, C_grid):
    i = 0
    no_update_count = 0
    grid_rotation = {0 : A_grid, 1 : B_grid, 2 : C_grid}
    while True:
        current_grid = grid_rotation[i % 3]
        cells_used = simplify_grid(current_grid)
        if cells_used == []:
            no_update_count += 1
            i += 1
            continue
        for j in range(1, 3):
            update_grids(grid_rotation[i % 3], cells_used)
        if no_update_count >= 3:
            break
        i += 1

for x in range(5):
    inp = input().split(', ')
    filled = [conv_loc(inp[x]) for x in range(4)]
    start = []
    i = 0
    for s in range(int(inp[5])):
        start.append((inp[i+5], conv_loc(inp[i+6])))
        i += 2
    find = int(inp[-1])
    A_grid = [[0 for i in range(4)] for j in range(4)]
    for cell in filled:
        A_grid[cell[0]][cell[1]] = -1
    B_grid, C_grid = A_grid[:], A_grid[:]