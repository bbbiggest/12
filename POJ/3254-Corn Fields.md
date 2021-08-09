## poj3254 - Corn Fields 题解



### 题目大意

给定 M 行 N 列 (1 ≤ M ≤ 12; 1 ≤ N ≤ 12) 的土地，然后给出每块土地的状态，只有为 1 的土地能种植，且要求种植的草地不能有公共边，求一共有多少种种植方案（一块都不种也算一种方案）。答案对 100,000,000 取模



### 解题思路

轮廓线 dp 题

从左到右从上到下考虑每块土地，然后因为只有该块地上面的和左边的会影响它，所以只需考虑一行的状态即可

用滚动数组节约内存

具体细节参考代码



### 代码

``` c++
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
```

