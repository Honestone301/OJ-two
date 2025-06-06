#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void heapify(vector<int> &res, int index, int len)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int biggest = index;

    if (left < len && res[biggest] < res[left])
        biggest = left;
    if (right < len && res[biggest] < res[right])
        biggest = right;
    if (index != biggest)
    {
        swap(res[index], res[biggest]);
        heapify(res, biggest, len);
    }
}

void heapsort(vector<int> &res)
{
    int len = res.size() - 1;
    for (int i = len / 2; i >= 0; i--)
    {
        heapify(res, i, len);
    }
    for (auto i : res)
        cout << i << " ";
    cout << endl;

    for (int i = len; i > 0; i--)
    {
        swap(res[i], res[0]);
        heapify(res, 0, i);
        for (auto i : res)
            cout << i << " ";
        cout << endl;
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

    heapsort(res);
    return 0;
}