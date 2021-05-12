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
        cin >> n;
        map<int, int> m;
        ll cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            cnt += m[a - i]++;
        }
        cout << cnt << '\n';
    }
    cout.flush();
    return 0;
}