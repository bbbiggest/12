#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const double eps = 1e-8;
int lines[20][20], lowunbit[1 << 20], dp[1 << 20];
double x[20], y[20];
void equation(double &x, double &y, double a1, double b1, double c1, double a2, double b2, double c2)
{
    y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
    x = (c1 - b1 * y) / a1;
}
int main()
{
    for (int i = 0; i < (1 << 18); i++)
    {
        int j = 1;
        for (; j <= 18 && i & (1 << (j - 1)); j++)
            ;
        lowunbit[i] = j;
    }
    int t;
    cin >> t;
    while (t--)
    {
        memset(lines, 0, sizeof(lines));
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (fabs(x[i] - x[j]) < eps)
                    continue;
                double a, b;
                equation(a, b, x[i] * x[i], x[i], y[i], x[j] * x[j], x[j], y[j]);
                if (a > -eps)
                    continue;
                for (int k = 1; k <= n; k++)
                    if (fabs(a * x[k] * x[k] + b * x[k] - y[k]) < eps)
                        lines[i][j] |= (1 << (k - 1));
            }
        for (int i = 0; i < (1 << n); i++)
        {
            int j = lowunbit[i];
            dp[i | (1 << (j - 1))] = min(dp[i | (1 << (j - 1))], dp[i] + 1);
            for (int k = 1; k <= n; k++)
                dp[i | lines[j][k]] = min(dp[i | lines[j][k]], dp[i] + 1);
        }
        cout << dp[(1 << n) - 1] << '\n';
    }
    return 0;
}