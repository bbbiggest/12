#include <iostream>
using namespace std;
const int MAX_N = 20;
bool d[MAX_N + 10][MAX_N + 10]; // d[i][j]表示“牛i”喜欢“谷仓j”
int dp[1 << MAX_N]; // dp[S]表示状态为S时的方案数量

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int p, j;
        cin >> p;
        while (p--)
        {
            cin >> j;
            d[i][j - 1] = true;
        }
    }
    dp[0] = 1;
    int ans = 0;
    for (int i = 0; i <= n; ++i) // 枚举每头牛，i == n 时仅统计答案
    {
        // 枚举{0,...,(1<<m)}中所包含的所有大小为i的子集
        int j = (1 << i) - 1; // 最小的子集为(1<<i)-1
        while (j < (1 << m))
        {
            for (int k = 0; i < n && k < m; ++k) // 枚举谷仓
            {
                // 若当前的“谷仓k”为空，且“牛i”喜欢“谷仓k”
                if (d[i][k] && !(j & (1 << k)))
                    dp[j | (1 << k)] += dp[j];
            }
            if (!i)
                break;
            if (i == n) // 统计答案
                ans += dp[j];
            int x = j & -j, y = j + x;
            j = ((j & ~y) / x >> 1) | y;
        }
    }
    cout << ans << '\n';
    return 0;
}