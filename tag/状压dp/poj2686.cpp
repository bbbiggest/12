#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int INF = 0x3fffffff;
double d[39][39], v[39], dp[1 << 9][39];
int main()
{
    int n, m, p, a, b;
    while (cin >> n >> m >> p >> a >> b && (n + m))
    {
        a--, b--;
        double ans = 1e18;
        for (int i = 0; i <= 30; i++)
            for (int j = 0; j <= 30; j++)
                d[i][j] = INF;
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < p; i++)
        {
            int l, r;
            double w;
            cin >> l >> r >> w;
            l--, r--;
            d[l][r] = d[r][l] = w;
        }
        for (int i = 0; i < (1 << 9); i++)
            for (int j = 0; j <= m; j++)
                dp[i][j] = INF;
        dp[0][a] = 0;
        int len = (1 << n);
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    for (int q = 0; q < m; q++)
                    {
                        for (int k = 0; k < m; k++)
                        {
                            if (q == k)
                                continue;
                            dp[i][k] = min(dp[i][k], dp[i - (1 << j)][q] + d[q][k] / v[j]);
                            if (k == b)
                                ans = min(ans, dp[i][k]);
                        }
                    }
                }
            }
        }
        if (ans >= INF - 1)
            cout << "Impossible" << endl;
        else
            printf("%.3lf\n", ans);
    }
    return 0;
}