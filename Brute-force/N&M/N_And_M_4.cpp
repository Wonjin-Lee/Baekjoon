// Baekjoon 15652

#include <iostream>
#include <vector>

using namespace std;

// 중복이 허락되는 수열 중 오름차순인 수열만 고르는 함수
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
        getNM(list, box, n, m, index + 1, i);
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

    getNM(list, box, n, m, 0, 0);
}