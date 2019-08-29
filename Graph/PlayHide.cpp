// Baekjoon 1697

#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 200000;

bool check[MAX+1];
int dist[MAX+1];

int N, K;

void playHide()
{
    queue<int> q;
    q.push(N); dist[N] = 0; check[N] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        // 뒤로 걷기
        if(now-1 >= 0)
        {
            if(check[now-1] == false)
            {
                q.push(now-1);
                check[now-1] = true;
                dist[now-1] = dist[now] + 1;
            }
        }
        // 앞으로 걷기
        if(now+1 < MAX)
        {
            if(check[now+1] == false)
            {
                q.push(now+1);
                check[now+1] = true;
                dist[now+1] = dist[now] + 1;
            }
        }
        // 앞으로 순간이동
        if(now * 2 < MAX)
        {
            if(check[now*2] == false)
            {
                q.push(now*2);
                check[now*2] = true;
                dist[now*2] = dist[now] + 1;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &K);

    playHide();

    printf("%d\n", dist[K]);
}