#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &res, int left, int mid, int right)
{
        if (left >= right) return;
    vector<int> copyy(right - left + 1, 0);
    int i = 0, j = mid;
    int zuo = left;
    while (zuo < mid && j < right)
    {
        if (res[j] < res[zuo])
            copyy[i++] = res[j++];
        else
            copyy[i++] = res[zuo++];
    }
    while (zuo < mid)
    {
        copyy[i++] = res[zuo++];
    }
    while (j < right)
    {
        copyy[i++] = res[j++];
    }
    for (int x = 0; x < right - left; x++)
    {
        res[left + x] = copyy[x];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> res(n, 0);
    for (auto &i : res)
    {
        cin >> i;
    }
    int widen = 0, begging = 0;
    for (widen = 1; widen <= n - 1; widen += widen)
    {
        for (begging = 0; begging <= n - 1; begging += widen * 2)
        {
            merge(res, begging, min(begging + widen, n), min(begging + widen * 2, n));
        }
        for (auto i : res)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}