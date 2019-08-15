// Beakjoon 1759
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(string &code)
{
    int ja = 0;
    int mo = 0;

    for(char x : code)
    {
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
            mo += 1;
        else
            ja += 1;
    }
    return mo >= 1 && ja >= 2;
}

void makeCode(vector<char>& alpha, int len, string code, int index)
{
    if(code.length() == len)
    {
        if(check(code))
        {
            cout << code << '\n';
        }
        return;
    }

    if(index >= alpha.size()) return;

    makeCode(alpha, len, code + alpha[index], index + 1);
    makeCode(alpha, len, code, index + 1);
}

int main()
{
    int len, alphaSize;
    cin >> len >> alphaSize;
    vector<char> alpha(alphaSize);
    for(int i=0; i < alphaSize; i++)
    {
        cin >> alpha[i];
    }
    sort(alpha.begin(), alpha.end());

    makeCode(alpha, len, "", 0);
}