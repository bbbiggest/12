#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int M = 100000000;
const int MAX_N = 12;
int a[MAX_N + 10][MAX_N + 10];
ll dp[2][1 << MAX_N]; // 滚动数组，dp[crt][S]表示当前行状态为S时的方案数

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    int crt = 0, nxt = 1; // crt当前行，nxt下一行
    dp[crt][0] = 1;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            memset(dp[nxt], 0, sizeof(dp[nxt]));
            for (int st = 0; st < (1 << n); ++st)
            {
                int nst = (st << 1) % (1 << n); // st的下一个状态
                dp[nxt][nst] += dp[crt][st];    // (i,j)不种草的情况
                if (!a[i][j])                   // 这块地不能种植
                    continue;
                if (i && (st & (1 << n - 1))) // (i,j)上面种草了
                    continue;
                if (j && (st & 1)) // (i,j)左边种草了
                    continue;
                dp[nxt][nst + 1] += dp[crt][st]; // 在(i,j)种草的情况
            }
            swap(crt, nxt);
        }
    ll ans = 0;
    for (int st = 0; st < (1 << n); ++st) // 计算答案
        ans = (ans + dp[crt][st]) % M;
    cout << ans << '\n';
    return 0;
}