#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX_N = 11;
ll dp[2][1 << MAX_N]; // 滚动数组，dp[crt][S]表示当前行状态为S时的方案数
int main()
{
    int h, w;
    while (cin >> h >> w && h)
    {
        memset(dp, 0, sizeof(dp));
        ll *crt = dp[0], *nxt = dp[1];
        crt[0] = 1;
        for (int i = h - 1; i >= 0; --i)
        {
            for (int j = w - 1; j >= 0; --j)
            {
                for (int used = 0; used < 1 << w; ++used)
                {
                    if (used >> j & 1)
                    {
                        // 不需要在 (i, j) 中放置砖块
                        nxt[used] = crt[used & ~(1 << j)];
                    }
                    else
                    {
                        ll res = 0;
                        // 横着放
                        if (j + 1 < w && !(used >> (j + 1) & 1))
                            res += crt[used | 1 << (j + 1)];
                        // 竖着放
                        if (i + 1 < h)
                            res += crt[used | 1 << j];
                        nxt[used] = res;
                    }
                }
                swap(crt, nxt);
            }
        }
        cout << crt[0] << '\n';
    }
    return 0;
}