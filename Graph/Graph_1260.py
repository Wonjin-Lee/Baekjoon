# Baekjoon 1260

def dfs(x):
    check[x] = True;
    print(x, end=' ')

    for i in range(0, len(edge[x])):
        if check[edge[x][i]] != True:
            dfs(edge[x][i])

def bfs(x):
    queue = []
    queue.append(x)
    check[x] = True

    while len(queue) != 0:
        parents = queue.pop(0)
        print(parents, end=' ')

        for i in range(0, len(edge[parents])):
            if check[edge[parents][i]] == False:
                check[edge[parents][i]] = True
                queue.append(edge[parents][i])
    

v, e, start = map(int, input().split())

check = [False for _ in range(v+1)]

edge = [[] for _ in range(v+1)]

for __ in range(e):
    n1, n2 = map(int, input().split())
    edge[n1].append(n2)
    edge[n2].append(n1)

for i in range(len(edge)):
    edge[i].sort()

dfs(start)

check = [False for _ in range(v+1)]

print()

bfs(start)