#include <bits/stdc++.h>
using namespace std;

int query(int l, int r)
{
    int ans;
    cout << "? " << l << ' ' << r << endl;
    cin >> ans;
    return r - l + 1 - ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t, k;
    cin >> n >> t >> k;
    int lb = 0, ub = n;
    while (ub - lb > 1)
    {
        int mid = (lb + ub) >> 1;
        if (query(1, mid) >= k)
            ub = mid;
        else
            lb = mid;
    }
    cout << "! " << ub << endl;
    return 0;
}