// Baekjoon 2178
#include <cstdio>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int maze[100][100];
int dist[100][100];
bool check[100][100];

void searchMaze(int x, int y)
{
    queue<pair<int, int> > q; q.push(make_pair(x, y));
    check[x][y] = true; dist[x][y] = 1;
    
    while(!q.empty())
    {
        x = q.front().first; y = q.front().second; q.pop();

        for(int i=0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(maze[nx][ny] == 1 && check[nx][ny] == false)
                {
                    q.push(make_pair(nx, ny)); check[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
        {
            scanf("%1d", &maze[i][j]);
        }
    }
    searchMaze(0, 0);

    printf("%d\n", dist[n-1][m-1]);
}