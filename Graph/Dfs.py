# 인접 행렬을 이용한 DFS

check = []
matrix = [
    [1, 2, 3, 4, 5],
    [1, 2, 3, 4, 5]
]

def dfs(x):
    check.insert(x, True)
    print(x, end=' ')
    
    for i in range(1, len(matrix[0])+1):
        if check[i] == False and matrix[x][i] == 1:
            dfs(i)