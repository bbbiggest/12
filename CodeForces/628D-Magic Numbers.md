## cf628D - Magic Numbers 题解



### 题目大意

给定数据 m, d(1 ≤ *m* ≤ 2000, 0 ≤ *d* ≤ 9), a, b(*a* ≤ *b* ≤ 10<sup>2000</sup>)，求 [a, b] 中有多少个”魔法数“，即仅有偶数位且偶数位必须为 d ，然后数字本身还要能被 m 整除的数（不含前导 0 ），计算结果对 (10<sup>9</sup> + 7) 取模

偶数位为从高到低，从 1 开始计数的偶数位，例：1x6x9x 中，x 代表的就是偶数位



### 解题思路

数位 dp 题

参数除了 **位置 pos** ，**最高位限制 limit** 之外

还要记录这个数字本身 `int pre` ，~~不然拿什么来除以m~~ 但是对于高达**两千位**的数字，显然不可能开这么大的数字进行**记忆化搜索**，所以根据我们的**数论**知识，可以将数字本身**对 m 取模**，这对最终结果不会有任何影响

还要一个参数 `bool even` 标记当前位是否为**偶数位** 

然后因为**前导 0** 在这题不构成影响，所以可以省掉这个参数

**10<sup>2000</sup>** 不能用之前的直接 `digitalDP(r) - digitalDP(l - 1)` 

为了避免**高精度**，直接 `digitalDP(r) - digitalDP(l)` ，然后再**单独判断**一下 l 是不是**魔法数**，加上去就行了

因为取模的缘故，差有可能是**负数**，要注意一下



### 代码

``` c++
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
using ll = long long;
const ll M = (int)1e9 + 7;
const int MAX_N = 2010;
int a[MAX_N];
ll dp[MAX_N][2010][2]; // dp[pos][pre][even]
int m, d;

// pos:从低到高第几位，pre:数字对m取模的结果
// even==true表示当前位为偶数位，limit:最高位限制标记
ll dfs(int pos, int pre, bool even, bool limit)
{
    if (pos < 0)
        return (pre % m == 0); // 数字本身是否能被m整除
    if (~dp[pos][pre][even] && !limit)
        return dp[pos][pre][even];
    ll res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        if (!even && i == d) // 在奇数位且为d的情况
            continue;
        else if (i == d) // 在偶数位且当前位数字为d的情况
            res = (res + dfs(pos - 1, (pre * 10 + i) % m, !even, limit && i == a[pos])) % M;
        else if (!even) // 在奇数位且当前位数字不为d的情况
            res = (res + dfs(pos - 1, (pre * 10 + i) % m, !even, limit && i == a[pos])) % M;
    }
    if (!limit)
        dp[pos][pre][even] = res;
    return res;
}

ll digitalDP(string num)
{
    int len = num.size();
    for (int i = 0; i < len; ++i)
        a[i] = num[len - 1 - i] - '0';
    return dfs(len - 1, 0, false, true);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string l, r;
    cin >> m >> d >> l >> r;
    ll ans = (digitalDP(r) - digitalDP(l) + M) % M;
    int i, num;
    for (i = num = 0; i < l.size(); ++i) // 对l单独判断一下
    {
        num = (num * 10 + l[i] - '0') % m;
        if ((i & 1) != (l[i] - '0' == d))
            break;
    }
    if (i == l.size() && !num)
        ans = (ans + 1) % M;
    cout << ans << '\n';
    return 0;
}
```

