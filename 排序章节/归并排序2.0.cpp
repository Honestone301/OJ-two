#include <iostream>
#include <vector>
using namespace std;
void mergge(vector<int> &res, int left, int mid, int right)
{
    vector<int> coppy(right - left, 0);
    int i = 0, j = mid;
    int zuo = left;
    while (j < right && zuo < mid)
    {
        if (res[zuo] < res[j])
            coppy[i++] = res[zuo++];
        else
            coppy[i++] = res[j++];
    }
    while (j < right)
    {
        coppy[i++] = res[j++];
    }
    while (i < mid)
    {
        coppy[i++] = res[zuo++];
    }
    for (int x = 0; x < right - left; x++)
    {
        res[left + x] = coppy[x];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> res(n, 0);
    for (auto &i : res)
        cin >> i;

    int widden = 0, beggin = 0;
    for (widden = 1; widden < n; widden += widden)
    {
        for (beggin = 0; beggin < n; beggin += widden * 2)
        {
            mergge(res, beggin, min(beggin + widden, n), min(beggin + 2 * widden, n));
        }
        for (auto i : res)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}