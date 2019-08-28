#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> edge[1001];
bool check[1001];

void bfs(int start)
{
    queue<int> q;

    check[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int i=0; i < edge[node].size(); i++)
        {
            int next = edge[node][i];
            if(check[next] == false)
            {
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int v, e;
    int component = 0;
    scanf("%d %d", &v, &e);

    for(int i=0; i < e; i++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        edge[n].push_back(m);
        edge[m].push_back(n);
    }

    for(int i=1; i <= v; i++)
    {
        if(check[i] == false)
        {
            bfs(i);
            component += 1;
        }
    }

    printf("%d \n", component);
}