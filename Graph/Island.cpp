// Baekjoon 4963

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int w, h;

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};

int map[50][50];
int group[50][50];

void findIsland(int x, int y, int cnt)
{
    queue<pair<int, int> > q; q.push(make_pair(x, y)); group[x][y] = cnt;

    while(!q.empty())
    {
        x = q.front().first; y = q.front().second; q.pop();
        for(int i=0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(0 <= nx && nx < w && 0 <= ny && ny < h)
            {
                if(map[nx][ny] == 1 && group[nx][ny] == 0)
                {
                    q.push(make_pair(nx, ny));
                    group[nx][ny] = cnt;
                }
            }
        }
    }
}

int main()
{
    while(true)
    {
        // w = 너비, h = 높이
        // 배열과 헷갈리면 오답임
        scanf("%d %d", &h, &w);

        if(w == 0 && h == 0)
            break;

        int cnt = 0;

        for(int i=0; i < w; i++)
        {
            for(int j=0; j < h; j++)
            {
                scanf("%1d", &map[i][j]);
                group[i][j] = 0;
            }
        }

        for(int i=0; i < w; i++)
        {
            for(int j=0; j < h; j++)
            {
                if(map[i][j] == 1 && group[i][j] == 0)
                {
                    findIsland(i, j, ++cnt);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}