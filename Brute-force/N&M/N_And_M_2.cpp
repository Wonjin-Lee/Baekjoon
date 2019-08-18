// Baekjoon 15650

#include <iostream>
#include <vector>

using namespace std;

// 오름차순인 수열만 고르는 함수
void getNM(vector<int> list, vector<int>& box, int n, int m, int index)
{
    if(box.size() == m)
    {
        for(int x : box)
            cout << x << ' ';
        cout << '\n';
    }

    if(index == n)
        return;

    for(int i=0; i < n; i++)
    {
        box.push_back(list[i]);
        getNM(list, box, n, m, i+1);
        box.pop_back();
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> list;
    vector<int> box;

    for(int i=1; i <= n; i++)
    {
        list.push_back(i);
    }

    getNM(list, box, n, m, 0);
}