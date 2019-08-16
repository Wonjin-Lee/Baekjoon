// Beakjoon 11723
#include <iostream>

using namespace std;

int set = 0;

int main()
{
    string oper;
    int n, num;
    cin >> n;

    for(int i=0; i < n; i++)
    {
        cin >> oper;
        if(oper == "add")
        {
            cin >> num;
            set = set | 1 << num;
        }
        else if(oper == "remove")
        {
            cin >> num;
            set = set & ~(1 << num);
        }
        else if(oper == "check")
        {
            cin >> num;
            if(set & (1 << num))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(oper == "toggle")
        {
            cin >> num;
            set = set ^ 1 << num;
        }
        else if(oper == "all")
        {
            set = (1 << 21) - 1;
        }
        else if(oper == "empty")
        {
            set = 0;
        }
    }
}