#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool next_permutation(int * arr, int n)
{
    int i = n-1;
    while(i > 0 && arr[i-1] >= arr[i]) i -= 1;
    if(i <= 0) return false; // 마지막 순열
   
    int j = n-1;
    while(arr[j] <= arr[i-1]) j -= 1;

    swap(arr[i-1], arr[j]);

    // 나머지를 오름차순으로 변경
    j = n-1;
    while(i < j)
    {
        swap(arr[i], arr[j]);
        i += 1, j -= 1;
    }
    return true;
}

int main()
{
   int n;
   cin >> n;

   vector<int> arr(n);
   for(int i=0; i < n; i++)
   {
       arr[i] = i+1;
   }
   do
   {
       for(int i=0; i < n; i++)
       {
           cout << arr[i] << ' ';
       }
       cout << '\n';
   } while(next_permutation(arr.begin(), arr.end()));
   return 0;
}