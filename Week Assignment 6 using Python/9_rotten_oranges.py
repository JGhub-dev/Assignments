from collections import deque

def orangesRotting(grid):
    rows, cols = len(grid), len(grid[0])
    q = deque()
    time = 0
    fresh = 0
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 2:
                q.append((i,j))
            elif grid[i][j] == 1:
                fresh += 1
    dirs = [(1,0),(-1,0),(0,1),(0,-1)]
    while q and fresh:
        for _ in range(len(q)):
            x,y = q.popleft()
            for dx,dy in dirs:
                nx,ny = x+dx,y+dy
                if 0<=nx<rows and 0<=ny<cols and grid[nx][ny]==1:
                    grid[nx][ny]=2
                    fresh-=1
                    q.append((nx,ny))
        time+=1
    return time if fresh==0 else -1
