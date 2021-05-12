#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> c(n);
        vector<int> cntl(n), cntr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> c[i];
            c[i]--;
            if (i < l)
                cntl[c[i]]++;
            else
                cntr[c[i]]++;
        }
        int matchl = 0, matchr = 0;
        for (int i = 0; i < n; ++i)
        {
            int m = min(cntl[i], cntr[i]);
            cntl[i] -= m;
            cntr[i] -= m;
            l -= m;
            r -= m;
            matchl += cntl[i] / 2;
            matchr += cntr[i] / 2;
        }
        int ans = min(l, r);
        if (l > r)
            ans += (l - r) / 2 + max(0, (l - r) / 2 - matchl);
        else
            ans += (r - l) / 2 + max(0, (r - l) / 2 - matchr);
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}