// Baekjoon 2267

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int map[30][30];
int check[30][30];
int answer[25*25];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

void bfs(int x, int y, int cnt)
{
    queue<pair<int, int> > q; q.push(make_pair(x, y)); check[x][y] = cnt;

    while(!q.empty())
    {
        x = q.front().first; y = q.front().second; q.pop();
        for(int i=0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < N)
            {
                if(map[nx][ny] == 1 && check[nx][ny] == 0)
                {
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = cnt;
                }
            }
        }
    }
}

int main()
{
    int cnt = 0;
    scanf("%d", &N);

    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            if(map[i][j] == 1 && check[i][j] == 0)
            {
                bfs(i, j, ++cnt);
            }
        }
    }

    printf("%d\n", cnt);

    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            answer[check[i][j]] += 1;
        }
    }
    
    sort(answer + 1, answer + cnt + 1);

    for(int i=1; i <= cnt; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}