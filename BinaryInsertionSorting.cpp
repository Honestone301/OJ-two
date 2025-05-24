#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        res[i] = val;
    }

    for (int i = 1; i < n; i++)
    {
        int low = 0, high = i - 1, key = res[i];
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (key < res[mid])
        }
    }
}