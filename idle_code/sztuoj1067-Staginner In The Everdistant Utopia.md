# SZTUoj1067 - Staginner In The Everdistant Utopia 题解




## 题目大意
[题目入口](http://10.1.97.60/csuoj/problemset/problem?pid=1067) 

大概是说，有个 n*n *(1 <= n <= 10)* 大小的土地，上面有 k  _(0 <= k <= 10 * 10)_  个国王，国王会攻击自己周围一圈的八个格子，问有多少种摆放国王的方法，使得每个国王的攻击范围内都没有其他的国王。



## 解题思路
由于国王的攻击范围只有自己周围的8个格子，所以对于点 (i, j) 仅需要考虑点 (i - 1, j - 1) 和 {(i, j') | j' < j} 和 {(i - 1, j') | j' >= j} 这 n+1 个格子即可，从而可以把这 n+1 个格子，也就是轮廓线，通过状态压缩编码进行记忆化搜索

这题虽然有2秒，但可能是有很多组重复的测试数据，直接状压dp还是不够，要预处理把10种n的结果都保存下来，记得要开 long long 的数组！！

嗯...大概就像下面那个表格那样，粉色的是 (i, j) ，黑色的是需要考虑的格子

<table><tbody>
    <tr>
        <th> </th><th> </th><th> </th><th> </th><th> </th><th> </th>
    </tr>
    <tr>
        <th> </th><th> </th><th> </th><th> </th><th> </th><th> </th>
    </tr>
    <tr>
        <td> </td>
        <td bgcolor="Black"> </td>
        <td bgcolor="Black"> </td>
        <td bgcolor="Black"> </td>
        <td bgcolor="Black"> </td>
        <td bgcolor="Black"> </td>
    </tr>
    <tr>
        <td bgcolor="Black"> </td>
        <td bgcolor="Black"> </td>
        <td bgcolor="Pink"> </td>
        <td> </td>
        <td> </td>
        <td> </td>
    </tr>
    <tr>
        <th> </th><th> </th><th> </th><th> </th><th> </th><th> </th>
    </tr>
    <tr>
        <th> </th><th> </th><th> </th><th> </th><th> </th><th> </th>
    </tr>
</table>
dp[crt] [st] [k] 表示当前轮廓线状态为 st 时，已经放了k个国王的方案共有多少种




## 复杂度分析
棋盘大小为 n<sup>2</sup>，状态有 2<sup>n + 1</sup> 种，再乘上国王的数目 k，所以时间复杂度为 O(k * n<sup>2</sup> * 2<sup>n + 1</sup> ) 



## 代码
```C++
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
```

