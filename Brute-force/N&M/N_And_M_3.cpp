// Baekjoon 15651

#include <iostream>
#include <vector>

using namespace std;

// 중복이 허락되는 수열을 모두 고르는 함수
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
        getNM(list, box, n, m, index+1);
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