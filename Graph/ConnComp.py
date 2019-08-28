# Baekjoon 11724

def bfs(start):
    queue = []
    queue.append(start)
    check[start] = True

    while len(queue) != 0:
        node = queue.pop(0)

        for i in range(len(edge[node])):
            next = edge[node][i]
            if check[next] == False:
                queue.append(next)
                check[next] = True

v, e = map(int, input().split())

check = [False for _ in range(v+1)]

edge = [[] for _ in range(v+1)]

component = 0

for i in range(e):
    m, n = map(int, input().split())
    edge[m].append(n)
    edge[n].append(m)

for i in range(1, v+1):
    if check[i] == False:
        bfs(i)
        component += 1

print(component)