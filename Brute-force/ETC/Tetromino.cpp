#include <iostream>

using namespace std;

int polyomino[19][3][2] = {
    { { 0, 1 }, { 0, 2 }, { 0, 3 } },
};

int map[500][500];

int main()
{
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
           cin >> map[i][j]; 
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            for(int k = 0; k < 19; k++)
            {
                int sum = map[i][j];
                for(int l = 0; l < 3; l++)
                {
                    int x = i + polyomino[k][l][0];
                    int y = j + polyomino[k][l][1];
                }
            }
        }
    }
}