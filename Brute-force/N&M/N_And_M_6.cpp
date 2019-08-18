// Baekjoon 15655

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력 받은 수열 중 m개의 오름차순인 수열만 고르는 함수
void getNM(vector<int> list, vector<int>& box, int n, int m, int index, int start)
{
    if(box.size() == m)
    {
        for(int x : box)
            cout << x << ' ';
        cout << '\n';
    }

    if(index == n)
        return;

    for(int i=start; i < n; i++)
    {
        box.push_back(list[i]);
        getNM(list, box, n, m, index + 1, i + 1);
        box.pop_back();
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> list(n);
    vector<int> box;

    for(int i=0; i < n; i++)
    {
        cin >> list[i];
    }

    sort(list.begin(), list.end());
    getNM(list, box, n, m, 0, 0);
}