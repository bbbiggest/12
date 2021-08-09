## poj3252 - Round Numbers 题解



### 题目大意

给定两个整数 a, b(1 ≤ a < b ≤ 2×10<sup>9</sup>) ，求 [a, b] 中有多少个”回合数“，即在二进制表示下 0 的数量大于等于 1 的数字



### 解题思路

数位 dp 题

十进制下不好求，那就转为用二进制进行数位 dp

参数除了 位置 pos ，前导 0 标志 lead ，最高位限制 limit 之外

增加记录 0 和 1 的数量的参数，然后用 `digitalDP(b) - digitalDP(a - 1)` 即可

但吧，本着省一个参数是一个的原则，决定只用一个 `int st` 参数，每遇到一个 0 就加一，遇到一个 1 就减一，这样最后只要 st 不是负数就能知道 0 的数量大于 1 

随之而来的就是可能会遇到负数的情况，比如 `dp[pos][-2]` 这种，所以将参考系从 0 升为 32 ，最后大于等于 32 的就是回合数



### 代码

``` c++
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX_N = 32; // 二进制整数也就32位
int a[MAX_N];
int dp[MAX_N][64];

// pos:从低到高第几位，st:32为初始值，遇到0加一，遇到1减一
// lead:前导0标记，limit:最高位限制标记
int dfs(int pos, int st, bool lead, bool limit)
{
    if (pos < 0)
        return (st >= 32); // 0的数量大于等于1的数量
    if (~dp[pos][st] && !limit && !lead)
        return dp[pos][st];
    int res = 0;
    int up = limit ? a[pos] : 1; // 这里注意二进制最高为1
    for (int i = 0; i <= up; ++i)
    {
        if (!i && lead) // 前一位为前导0
            res += dfs(pos - 1, st, true, limit && i == a[pos]);
        else // 如果i为0，st就加一；i为1就减一
            res += dfs(pos - 1, st + (i ? -1 : 1), false, limit && i == a[pos]);
    }
    if (!limit && !lead)
        dp[pos][st] = res;
    return res;
}

int digitalDP(int num)
{
    int len;
    for (len = 0; num; num >>= 1) // 二进制
        a[len++] = num & 1;
    memset(dp, -1, sizeof(dp));
    return dfs(len - 1, 32, true, true);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << digitalDP(b) - digitalDP(a - 1) << '\n';
    return 0;
}
```

