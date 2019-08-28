#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> edge[1001];
bool check[1001];

void dfs(int start)
{
    check[start] = true;
    printf("%d ", start);

    for(int i=0; i < edge[start].size(); i++)
    {
        int next = edge[start][i];
        if(check[next] == false)
        {
            dfs(next);
        }
    }
}

void bfs(int start)
{
    memset(check, false, sizeof(check));
    queue<int> q;

    check[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        printf("%d ", node);

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, start;
    cin >> v >> e >> start;

    for(int i=0; i < e; i++)
    {
        int n, m;
        cin >> n >> m;

        edge[n].push_back(m);
        edge[m].push_back(n);
    }

    for(int i=0; i <= v; i++)
    {
        sort(edge[i].begin(), edge[i].end());
    }

    dfs(start);
    puts("");
    bfs(start);
    puts("");
}