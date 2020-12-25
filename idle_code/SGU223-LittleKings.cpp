#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN = 10;
const int MAXK = MAXN * MAXN, MAXS = 1 << (MAXN + 1);
ll dp[2][MAXS + 10][MAXK + 10];

int main()
{
    int n, k;
    cin >> n >> k;
    ll(*crt)[MAXK + 10] = dp[0], (*next)[MAXK + 10] = dp[1];
    crt[0][0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            memset(next, 0, sizeof(ll) * (MAXS + 10) * (n * n + 10));
            for (int st = 0; st < (1 << n + 1); ++st)
            {
                int nst = (st << 1) % (1 << n + 1);
                for (int cnt = 0; cnt <= k; ++cnt)
                {
                    next[nst][cnt] += crt[st][cnt];
                    if (cnt >= k)
                        continue;
                    if (i && j && (st & (1 << n)))
                        continue;
                    if (i && (st & (1 << n - 1)))
                        continue;
                    if (i && (j < n - 1) && (st & (1 << n - 2)))
                        continue;
                    if (j && (st & 1))
                        continue;
                    next[nst + 1][cnt + 1] += crt[st][cnt];
                }
            }
            swap(crt, next);
        }
    ll ans = 0;
    for (int st = 0; st < (1 << n + 1); ++st)
        ans += crt[st][k];
    cout << ans << endl;
    return 0;
}
