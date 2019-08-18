// Baekjoon 15649

#include <iostream>
#include <vector>

using namespace std;

bool check[9];
int box[9];

// 사전순으로 수열을 출력하는 함수
void getNM(int index, int n, int m)
{
    if(index == m)
    {
        for(int i=0; i < m; i++)
        {   
            cout << box[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i <= n; i++)
    {
        if(check[i]) continue;
        check[i] = true; box[index] = i;

        getNM(index + 1, n, m);
        check[i] = false;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    getNM(0, n, m);
}