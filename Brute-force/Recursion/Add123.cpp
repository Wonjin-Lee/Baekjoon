#include <iostream>
#include <vector>

using namespace std;

int go(int sum, int goal)
{
    if(sum > goal)
        return 0;

    if(sum == goal)
        return 1;

    int now = 0;

    for(int i=1; i <= 3; i++)
    {
        now += go(sum + i, goal);
    }
    return now;
}

int main()
{
    int testCase;
    cin >> testCase;

    for(int i=0; i < testCase; i++)
    {
        int num;
        cin >> num;

        cout << go(0, num) << '\n';
    }
}