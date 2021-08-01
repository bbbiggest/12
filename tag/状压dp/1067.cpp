#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN = 10;
const int MAXK = MAXN * MAXN, MAXS = 1 << (MAXN + 1);
ll dp[2][MAXS + 10][MAXK + 10]; // 滚动数组，循环利用
ll ans[MAXN + 10][MAXK + 10];   // 保存答案，避免重复计算

int main()
{
    int n, k;
    for (n = 1; n <= 10; ++n) // 预处理，计算n为1到10的每个情况
    {
        k = n * n; // k取最大
        memset(dp[0], 0, sizeof(dp[0]));
        ll (*crt)[MAXK + 10] = dp[0], (*next)[MAXK + 10] = dp[1];
        crt[0][0] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                memset(next, 0, sizeof(ll) * (MAXS + 10) * (n * n + 10));
                for (int st = 0; st < (1 << n + 1); ++st)
                {
                    int nst = (st << 1) % (1 << n + 1); // st的下一个状态
                    for (int cnt = 0; cnt <= k; ++cnt)
                    {
                        next[nst][cnt] += crt[st][cnt]; // (i,j)不放国王的情况
                        if (cnt >= k)                   // 是否已放满了k个国王
                            continue;
                        if (i && j && (st & (1 << n))) // (i,j)左上方有国王
                            continue;
                        if (i && (st & (1 << n - 1))) // (i,j)上方有国王
                            continue;
                        if (i && (j < n - 1) && (st & (1 << n - 2))) // (i,j)右上方有国王
                            continue;
                        if (j && (st & 1)) // (i,j)左边有国王
                            continue;
                        next[nst + 1][cnt + 1] += crt[st][cnt]; // (i,j)放国王的情况
                    }
                }
                swap(crt, next);
            }
        for (k = 0; k <= n * n; ++k)                  // 取k的所有情况
            for (int st = 0; st < (1 << n + 1); ++st) // 计算答案
                ans[n][k] += crt[st][k];
    }
    while (cin >> n >> k)
        cout << ans[n][k] << endl;
    return 0;
}