// Beakjoon 1182
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cnt = 0;
int input, n, m;

void sequence(vector<int>& seqList, int n, int sum, int index)
{
    if(index == input)
    {
        if(sum == n)
        {
            cnt += 1;
        }
        return;
    }

    sequence(seqList, n, sum + seqList[index], index + 1);
    sequence(seqList, n, sum, index + 1);
}

int main()
{
    vector<int> seq;

    cin >> input >> n;
    
    for(int i=0; i < input; i++)
    {
        cin >> m;
        seq.push_back(m);
    }

    sequence(seq, n, 0, 0);

    // 공집합의 경우
    if(n == 0) cnt -= 1;

    cout << cnt << '\n';
}