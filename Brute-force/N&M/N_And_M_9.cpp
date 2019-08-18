// Baekjoon 15663

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check[9];
int box[9];

void getNM(vector<int>& list, int n, int m, int index)
{
    if(m == index)
    {
        for(int i=0; i < m; i++)
        {
            cout << box[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=0; i < n; i++)
    {
        if(check[i]) continue;
        check[i] = true; box[index] = list[i];
        getNM(list, n, m, index + 1);
        check[i] = false;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> list(n);

    for(int i=0; i < n; i++)
    {
        cin >> list[i];
    }

    sort(list.begin(), list.end());
    list.erase(unique(list.begin(), list.end()), list.end());

    for(int i=0; i < n; i++)
    {
        cout << list[i] << ' ';
    }

    // getNM(list, n, m, 0);
}