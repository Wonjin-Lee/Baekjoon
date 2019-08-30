// Baekjoon 14226

#include <cstdio>
#include <queue>
#include <tuple>
#include <cstring>
#include <iostream>

using namespace std;

int dist[1001][1001];

int n;

void emoticon()
{
    queue<pair<int, int> > q;
    dist[1][0] = 0;
    q.push(make_pair(1, 0));

    while(!q.empty())
    {
        int s, c;
        s = q.front().first; c = q.front().second;
        q.pop();
        
        // 복사
        if(dist[s][s] == -1)
        {
            dist[s][s] = dist[s][c] + 1;
            q.push(make_pair(s, s));
        }

        // 클립보드에서 가져와 붙여넣기
        if(s + c <= n && dist[s+c][c] == -1)
        {
            dist[s+c][c] = dist[s][c] + 1;
            q.push(make_pair(s+c, c));
        }

        // 화면에 있는 이모티콘 하나 삭제
        if(s - 1 >= 0 && dist[s-1][c] == -1)
        {
            dist[s-1][c] = dist[s][c] + 1;
            q.push(make_pair(s-1, c));
        }
    }
}

int main()
{
    scanf("%d", &n);
    memset(dist, -1, sizeof(dist));

    emoticon();

    int answer = -1;
    for(int i=1; i <= n; i++)
    {
        if(dist[n][i] != -1)
        {
            if(answer == -1 || answer > dist[n][i])
            {
                answer = dist[n][i];
            }
        }
    }

    printf("%d\n", answer);
}