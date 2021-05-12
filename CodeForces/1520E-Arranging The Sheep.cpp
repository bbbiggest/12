#include <bits/stdc++.h>
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
        int n;
        string s;
        cin >> n >> s;
        vector<int> a;
        for (int i = 0; i < n; ++i)
            if (s[i] == '*')
                a.push_back(i);
        int mid = (a.size() - 1) / 2;
        ll ans = 0;
        int c = 1;
        for (auto x : a)
        {
            if (x - a[mid] == 0)
                c = 0;
            ans += abs(x - a[mid]) - c;
            c++;
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}