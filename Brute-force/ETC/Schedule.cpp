// Backjoon 1476
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int calander[3];
    
    memset(calander, 0, sizeof(calander));

    int earth, sun, moon;

    cin >> earth >> sun >> moon;

    int cnt = 0;

    while(true)
    {
        calander[0]++;
        calander[1]++;
        calander[2]++;
        if(calander[0] == 16)
            calander[0] = 1;
        if(calander[1] == 29)
            calander[1] = 1;
        if(calander[2] == 20)
            calander[2] = 1;

        cnt++;

        if(calander[0] == earth && calander[1] == sun && calander[2] == moon)
            break;
    }

    cout << cnt << endl;
}