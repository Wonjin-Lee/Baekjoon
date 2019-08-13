#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool next_permutation(int * arr, int n)
{
    int i = n-1;
    while(i > 0 && arr[i-1] >= arr[i]) i -= 1;
    if(i <= 0) return false;

    int j = n-1;
    while(arr[j] <= arr[i-1]) j -= 1;
    swap(arr[i-1], arr[j]);
    j = n-1;

    while(i < j)
    {
        swap(arr[i], arr[j]);
        i += 1, j -= 1;
    }
    return true;
}

void sorting(vector<int>& arr, int n)
{
    for(int i=0; i < n-1; i++)
    {
        for(int j=i+1; j < n; j++)
        {
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    int n;
    int ret = -1;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i < n; i++)
    {
        cin >> arr[i];
    }
    // 정렬을 해주어야 가장 첫 순열로 시작
    sorting(arr, n);

    do
    {
        int sum = 0;
        for(int i=0; i < n-1; i++)
        {
            sum += abs(arr[i] - arr[i+1]);
        }
        if(sum > ret)
            ret = sum;
    }
    while(next_permutation(arr.begin(), arr.end()));

    cout << ret << endl;
}