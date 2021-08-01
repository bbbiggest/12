#include <iostream>
using namespace std;
typedef long long ll;
ll cnt[2000], ok[2000];
ll dp[10][100][2000];
int main()
{
    int n, k, num;
    cin >> n >> k;
    for (int s = 0; s < (1 << n); s++)
    {
        int tot = 0, s1 = s;
        while (s1)
        {
            if (s1 & 1)
                tot++;
            s1 >>= 1;
        }
        cnt[s] = tot;
        if ((((s << 1) | (s >> 1)) & s) == 0)
            ok[++num] = s;
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int l = 1; l <= num; l++)
        {
            int s1 = ok[l];
            for (int r = 1; r <= num; r++)
            {
                int s2 = ok[r];
                if (((s2 | (s2 << 1) | (s2 >> 1)) & s1) == 0)
                {
                    for (int j = 0; j <= k; j++)
                        if (j - cnt[s1] >= 0)
                            dp[i][j][s1] += dp[i - 1][j - cnt[s1]][s2];
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= num; i++)
        ans += dp[n][k][ok[i]];
    cout << ans << '\n';
    return 0;
}