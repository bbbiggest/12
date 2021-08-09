## cf55D - Beautiful numbers 题解



### 题目大意

给定 t(1 ≤ *t* ≤ 10) 组数据，每组两个整数 l, r(1 ≤ l ≤ r ≤ 9×10<sup>18</sup>) ，求 [l, r] 中有多少个”漂亮数“，即能被自己每一位上的非零数字整除的数



### 解题思路

数位 dp 题

首先吧，1, 2, ... , 9 这 9 个数字的**最小公倍数**是 2520

然后回到题目上，能被自己的每一位数整除，但显然不能把每一位都记录下来，记录它们的最小公倍数也是一样的，能被那几个数**整除**的数字同样也能被**它们的最小公倍数**整除

~~所以我们要开 2521 大小的数组，~~ 所以我们可以不必记录每一位上的数字，只需记录它们的最小公倍数，然后最后判断是否能整除即可

当然参数除了 **位置 pos** ，**最高位限制 limit** ，以及刚刚说的**最小公倍数 M** 之外

还要记录这个数字本身 `int pre` ，~~不然拿什么来除以最小公倍数~~ 但是对于高达 9×10<sup>18</sup> 的数字，显然不可能开这么大的数字进行**记忆化搜索**，所以根据我们的**数论**知识，可以将数字本身**对 2520 取模**，这对最终结果不会有任何影响

但是这样吧，就发现 `dp[pos][pre][M]` 数组**第一维** `[pos]` 需要开 19 位数 ~~我开 20 不过分吧~~ ，**第二维**存数字本身对 2520 取模的结果 `[pre]` 也就是最少要开 2520 个，然后**第三维**存最小公倍数的 `[M]` ，这个最少要开 2521 个，因为会需要用到 `[2520]` 。然后 `20 * 2520 * 2521` 约为 **10<sup>8</sup>** ，这太大了，会超过内存限制

为了省一点内存，~~我告诉你~~ 我们发现**第三维并不需要这么大**，1 到 9 这 9 个数字进行随机组合求公倍数，其实也就只有 **48 个**，所以我们可以第三维只开 48 ~~开 50 吧凑个整~~，然后**预处理**将这 48 个公倍数用 map **映射**一下

然后因为**前导 0** 在这题不构成影响，所以可以省掉这个参数



### 代码

``` c++
#include <iostream>
#include <cstring>
#include <numeric>
using namespace std;
using ll = long long;
const int MAX_N = 20;
int a[MAX_N];
ll dp[MAX_N][2520][50]; // dp[pos][pre][M]
int mp[2521]; // 字典，存每个公倍数被映射为多少

// pos:从低到高第几位，pre:数字本身，limit:最高位限制标记
// M: 每一位上的数字的最小公倍数
ll dfs(int pos, int pre, int M, bool limit)
{
    if (pos < 0)
        return (pre % M == 0);
    if (~dp[pos][pre][mp[M]] && !limit)
        return dp[pos][pre][mp[M]];
    ll res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        if (!i) // 0的情况特殊处理一下
            res += dfs(pos - 1, (pre * 10 + i) % 2520, M, limit && i == a[pos]);
        else
            res += dfs(pos - 1, (pre * 10 + i) % 2520, lcm(M, i), limit && i == a[pos]);
    }
    if (!limit)
        dp[pos][pre][mp[M]] = res;
    return res;
}

ll digitalDP(ll num)
{
    int len;
    for (len = 0; num; num /= 10)
        a[len++] = num % 10;
    return dfs(len - 1, 0, 1, true);
}

int main()
{
    int cnt = 0;
    for (int i = 1; i <= 2520; ++i) // 预处理，将每个可能的公倍数映射为0~47
        if (2520 % i == 0)
            mp[i] = cnt++;
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << digitalDP(r) - digitalDP(l - 1) << '\n';
    }
    return 0;
}
```

