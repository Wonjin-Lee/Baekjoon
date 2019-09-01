// Baekjoon 13549

#include <cstdio>
#include <queue>

const int MAX = 1000000;
bool check[MAX];
int dist[MAX];

using namespace std;

int n, k;

void playHide(int n)
{
    queue<int> q;
    queue<int> next_q;

    q.push(n); check[n] = true; dist[n] = 0;

    while(!q.empty())
    {
        int now = q.front(); q.pop();

        if(now*2 < MAX)
        {
            if(check[now*2] == false)
            {
                q.push(now*2);
                check[now*2] = true;
                dist[now*2] = dist[now];
            }
        }

        if(now-1 >= 0)
        {
            if(check[now-1] == false)
            {
                next_q.push(now-1);
                check[now-1] = true;
                dist[now-1] = dist[now] + 1;
            }
        }

        if(now+1 < MAX)
        {
            if(check[now+1] == false)
            {
                next_q.push(now+1);
                check[now+1] = true;
                dist[now+1] = dist[now] + 1;
            }
        }

        if(q.empty())
        {
            q = next_q;
            next_q = queue<int>();
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);

    playHide(n);

    printf("%d\n", dist[k]);
}