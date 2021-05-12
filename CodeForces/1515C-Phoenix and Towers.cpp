#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m >> x;
        vector<int> h(n);
        for (int i = 0; i < n; ++i)
            cin >> h[i];
        vector<int> ind(n);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](int i, int j) { return h[i] < h[j]; });
        multiset<P> s;
        vector<int> y(n);
        for (int i = 0; i < m; ++i)
        {
            s.insert(P(h[ind[i]], i + 1));
            y[ind[i]] = i + 1;
        }
        for (int i = n - 1; i >= m; --i)
        {
            P e = *s.begin();
            s.erase(s.begin());
            y[ind[i]] = e.second;
            s.insert(P(e.first + h[ind[i]], e.second));
        }
        if (s.rbegin()->first - s.begin()->first <= x)
        {
            cout << "YES\n";
            for (int i = 0; i < n; ++i)
                cout << y[i] << " \n"[i == n - 1];
        }
        else
            cout << "NO\n";
    }
    cout.flush();
    return 0;
}