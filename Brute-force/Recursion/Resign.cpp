// Beakjoon 14501
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> schedule;
vector<int> pay;
int maximum = 0;
int n;

void counseling(int sum, int day)
{
    if(day == n)
    {
        if(sum > maximum)
            maximum = sum;
        return;
    }

    if(day > n)
        return;

    counseling(sum, day + 1);
    counseling(sum + pay[day], day + schedule[day]);
}

int main()
{
    cin >> n;

    for(int i=0; i < n; i++)
    {
        int m, n;
        cin >> m >> n;
        schedule.push_back(m);
        pay.push_back(n);
    }

    counseling(0, 0);

    cout << maximum << '\n';
}