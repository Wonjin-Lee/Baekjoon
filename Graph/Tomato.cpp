// Baekjoon 7576

#include <cstdio>
#include <queue>

using namespace std;

int m, n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int box[1000][1000];
int dist[1000][1000];
queue<pair<int, int> > q;

// BFS를 이용해서 탐색
void growTomato()
{
    int x, y;
    while(!q.empty())
    {
        x = q.front().first; y = q.front().second; q.pop();
        for(int i=0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(box[nx][ny] == 0 && dist[nx][ny] == -1)
                {
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
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
            scanf("%d", &box[i][j]);
            dist[i][j] = -1;
            
            // 익은 토마토는 바로 큐에 넣어준다.
            if(box[i][j] == 1)
            {
                q.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }
    growTomato();

    int answer = 0;

    // 가장 큰 dist 값을 답으로
    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
        {
            if(answer < dist[i][j])
                answer = dist[i][j];
        }
    }

    // 익은 토마토와 인접하지 못해서 익은 못한 토마토를 체크
    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
        {
            if(box[i][j] == 0 && dist[i][j] == -1)
            {
                answer = -1;
            }
        }
    }
    printf("%d\n", answer);
}