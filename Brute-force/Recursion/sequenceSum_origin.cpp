// Beakjoon 1182
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sequence(vector<int>& seqList, int n, int sum, int index)
{
    if(sum == n && index == (int)seqList.size())
        return 1;

    if(index >= seqList.size() && sum != n)
        return 0;

    // 고르지 않는 경우를 추가
    int cnt = sequence(seqList, n, sum, (int)seqList.size());
    for(int i=index; i < seqList.size(); i++)
    {
        cnt += sequence(seqList, n, sum + seqList[i], i + 1);
    }
    return cnt;
}

int main()
{
    int input, n, result;
    int m;

    vector<int> seq;

    cin >> input >> n;

    for(int i=0; i < input; i++)
    {
        cin >> m;
        seq.push_back(m);
    }

    result = sequence(seq, n, 0, 0);
    if(n == 0) result -= 1;

    cout << result << '\n';
}