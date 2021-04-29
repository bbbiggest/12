#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        vector<int> a(n), ind(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector<bool> used(n);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](const int &x, const int &y) { return a[x] < a[y]; });
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[ind[i]] > p)
                break;
            for (int j = ind[i]; j > 0; --j)
            {
                if (used[j - 1])
                    break;
                if (a[j - 1] % a[ind[i]])
                    break;
                used[j - 1] = true;
                ans += a[ind[i]];
            }
            for (int j = ind[i]; j < n - 1; ++j)
            {
                if (used[j])
                    break;
                if (a[j + 1] % a[ind[i]])
                    break;
                used[j] = true;
                ans += a[ind[i]];
            }
        }
        for (int i = 0; i < n - 1; ++i)
        {
            if (!used[i])
                ans += p;
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}