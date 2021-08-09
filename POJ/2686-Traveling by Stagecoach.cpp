#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;
const double INF = 1e15;
const int MAX_N = 8;
const int MAX_M = 30;
int t[MAX_N];
int d[MAX_M][MAX_M]; // 图的邻接矩阵表示（-1表示没有边）

// dp[S][v]:=到达剩下的车票集合为S并且现在在城市v的状态所需要的最小花费
double dp[1 << MAX_N][MAX_M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, p, a, b;
    cout << fixed << setprecision(3); // 保留3位小数
    while (cin >> n >> m >> p >> a >> b && n)
    {
        memset(d, -1, sizeof(d));
        for (int i = 0; i < n; ++i)
            cin >> t[i];
        while (p--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            d[x - 1][y - 1] = z;
            d[y - 1][x - 1] = z; // 无向图
        }
        for (int i = 0; i < (1 << n); ++i)
            fill(dp[i], dp[i] + m, INF); // 用足够大的值初始化
        dp[(1 << n) - 1][a - 1] = 0;     // 起点的费用设为0
        double res = INF;
        for (int S = (1 << n) - 1; S >= 0; --S)
        {
            res = min(res, dp[S][b - 1]);
            for (int v = 0; v < m; ++v) // 枚举车票起始的城市
            {
                for (int i = 0; i < n; ++i) // 枚举车票
                {
                    if (!(S >> i & 1)) // 若这张票已近用过了
                        continue;
                    for (int u = 0; u < m; ++u) // 枚举车票到达的城市
                    {
                        if (d[v][u] < 0) // 若不存在边
                            continue;

                        // 使用车票i，从v移动到u
                        dp[S & ~(1 << i)][u] =
                            min(dp[S & ~(1 << i)][u], dp[S][v] + (double)d[v][u] / t[i]);
                    }
                }
            }
        }
        if (res == INF)
            cout << "Impossible\n";
        else
            cout << res << '\n';
    }
    cout.flush();
    return 0;
}