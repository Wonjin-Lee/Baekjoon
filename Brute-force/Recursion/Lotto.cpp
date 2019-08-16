// Beakjoon 6603
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void lottery(vector<int>& lotto, vector<int>& cand, int index)
{
    if(cand.size() == 6)
    {
        for(int i=0; i < cand.size(); i++)
        {
            cout << cand[i] << ' ';
        }
        cout << '\n';
        return;
    }

    if(index >= lotto.size())
        return;

    for(int i=index; i < lotto.size(); i++)
    {
        cand.push_back(lotto[i]);
        lottery(lotto, cand, i+1);
        cand.pop_back();
    }
}

int main()
{
    while(true)
    {
        vector<int> cand;
        vector<int> lotto;
        
        int n, m;
        cin >> n;

        if(n == 0)
            break;
        
        for(int i=0; i < n; i++)
        {
            cin >> m;
            lotto.push_back(m);
        }
        lottery(lotto, cand, 0);
        cout << '\n';
    }
}