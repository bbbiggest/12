#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN = 9;
const int MAXK = MAXN * MAXN, MAXS = 1 << (MAXN + 1);
ll dp[2][MAXS + 10][MAXK + 10]; // 滚动数组，循环利用

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
    ll ans = 0;
    for (int st = 0; st < (1 << n + 1); ++st) // 计算答案
        ans += crt[st][k];
    cout << ans << '\n';
    return 0;
}