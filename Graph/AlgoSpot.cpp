// Baekjoon 1261

#include <cstdio>
#include <queue>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int m, n;

bool check[555][555];

int dist[555][555];
int map[555][555];

void escapeMaze()
{
    queue<pair<int, int> > q;
    queue<pair<int, int> > next_q;
    q.push(make_pair(0, 0)); check[0][0] = true; dist[0][0] = 0;

    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(check[nx][ny] == false && map[nx][ny] == 0)
                {
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                    dist[nx][ny] = dist[x][y];
                }

                if(check[nx][ny] == false && map[nx][ny] == 1)
                {
                    next_q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        if(q.empty())
        {
            q = next_q;
            next_q = queue<pair<int, int> >();
        }
    }
}

int main()
{
    scanf("%d %d", &m, &n);

    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    escapeMaze();

    printf("%d\n", dist[n-1][m-1]);
}