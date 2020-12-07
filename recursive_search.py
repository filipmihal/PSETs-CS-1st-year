import sys
def cave_search(cave, cave_stats, x, y):
    if cave[y][x] == '.':
        cave_stats[0] += 1
        cave_stats[1] += y
        cave_stats[2] += x
        cave[y][x] = 'x'
        if y != 0:
            cave_search(cave, cave_stats, x, y-1)
        if y != len(cave)-1:
            cave_search(cave, cave_stats, x, y+1)
        if x != 0:
            cave_search(cave, cave_stats, x-1, y)
        if x != len(cave[0])-1:
            cave_search(cave, cave_stats, x+1, y)

cave = [] 
row = 0
for line in sys.stdin:
     cave.append(line)

for line in range(len(cave)):
    cave[line] = [char for char in cave[line]]
cave_result = 0
cave_y = 0
cave_x = 0
for y in range(len(cave)):
    for x in range(len(cave[0])): 
        cave_stats = [0,0,0]
        cave_search(cave, cave_stats, x, y)
        if cave_result < cave_stats[0]:
            cave_result = cave_stats[0]
            cave_y = cave_stats[1]/cave_stats[0]
            cave_x = cave_stats[2]/cave_stats[0]
print(cave_result, int(cave_y), int(cave_x))
