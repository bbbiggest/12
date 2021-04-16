#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> a(n), c(n), p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> c[i];
        ans += c[i];
        c[i] += a[i];
        p[i] = i;
    }
    sort(p.begin(), p.end(), [&](const int &x, const int &y) {return a[x] < a[y];});
    int x = a[p[0]];
    for (int i = 0; i < n; ++i)
    {
        if (a[p[i]] > x)
            ans += a[p[i]] - x;
        x = max(x, c[p[i]]);
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}