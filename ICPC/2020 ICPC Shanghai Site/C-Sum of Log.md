## (2020 ICPC Shanghai Site) Problem C - Sum of Log 题解



### 题目大意

给定 T(1 ≤ T ≤ 10<sup>5</sup>) 组数据，每组两个整数 X, Y(0 ≤ X,Y ≤ 1×10<sup>18</sup>) ，求 

$$
\sum_{i=0}^{X}\sum_{j=[i=0]}^{Y}[i\&j=0]\lfloor\log_2(i+j)+1\rfloor
$$

<img width="226" alt="屏幕截图 2021-08-09 204128" src="https://user-images.githubusercontent.com/60065681/128707686-b5b7d507-aaac-4fc2-83db-cee450a6bcd6.png">


其中：

+ & 表示按位与

+ 如果 A 为真，则 [A] 等于 1 ，反之等于 0 
+ ⌊x⌋ 表示 x 向下取整

计算结果对 (10<sup>9</sup> + 7) 取模



### 解题思路

也就是在 `i & j == 0` 的情况下，求二进制表示下 max(i, j) 中最靠右的那个 1 是第几位

可以用**二进制**的数位 dp 求解

同时对 **x 和 y** 进行记忆化搜索并统计结果

具体看代码



### 代码

``` c++
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const ll M = (int)1e9 + 7;
int a[32], b[32];
ll dp[32][2][2]; // dp[pos][lim1][lim2]

// pos:当前位, lead:前导0标志, lim1:x最高位限制标志, lim2:y最高位限制标志
ll dfs(int pos, bool lead, bool lim1, bool lim2)
{
    if (pos < 0)
        return 1;
    if (~dp[pos][lim1][lim2] && !lead)
        return dp[pos][lim1][lim2];
    ll res = 0;
    int up1 = lim1 ? a[pos] : 1, up2 = lim2 ? b[pos] : 1;
    for (int i = 0; i <= up1; ++i)
    {
        for (int j = 0; j <= up2; ++j)
        {
            // [i&j=0] is false
            if (i & j)
                continue;

            // 当出现前导0之后的第一个1时，log(i+j)+1=pos+1
            // 之后的数字最高位1都是此位，即pos+1
            if (lead && (i || j))
                res = (res + (pos + 1) * dfs(pos - 1, false, lim1 && i == a[pos], lim2 && j == b[pos]) % M) % M;
            else
                res = (res + dfs(pos - 1, (lead && !i && !j), lim1 && i == a[pos], lim2 && j == b[pos])) % M;
        }
    }
    if (!lead)
        dp[pos][lim1][lim2] = res;
    return res;
}

ll digitalDP(int x, int y)
{
    memset(dp, -1, sizeof(dp));
    int len;
    for (len = 0; (x || y); x >>= 1, y >>= 1, ++len)
    {
        // 为了防止受上一组数据的影响，即使xy其中一个已为0，也继续填0上去
        // 当然也可以先memset(a, 0, sizeof(a));全部清为0
        a[len] = (x & 1);
        b[len] = (y & 1);
    }
    return dfs(len - 1, true, true, true);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int ans = (digitalDP(x, y) - 1 + M) % M; // 减去(i==0&&j==0)的情况
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
```

