#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int M = (int)1e9 + 7;
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int y = a[0];
        for (int i = 1; i < n; ++i)
            y &= a[i];
        int cnt = count(a.begin(), a.end(), y);
        ll ans = ((ll)cnt * (cnt - 1)) % M;
        for (int i = 1; i <= n - 2; ++i)
            ans = (ans * i) % M;
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}