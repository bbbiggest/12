## 洛谷P2657 - windy数 题解



### 题目大意

给定两个整数 a, b(1 ≤ a ≤ b ≤ 2×10<sup>9</sup>) ，求 [a, b] 中有多少个不含前导零且相邻两个数字之差至少为 2 的正整数



### 解题思路

数位 dp 模板题，用 `digitalDP(b) - digitalDP(a - 1)` 即可

记录前一位数就行，题目要求不包括前导0的情况，但因为记录了前一位数，所以可以省掉前导0标志的参数，用一个前一位数不会出现的且不影响结果的数字。比如前一位数不可能是负数或者两位数，然后又要满足 `abs(pre - i) < 2` ，所以小于等于 -2 或者 大于等于 11 的数字都行，但是因为 `dp[pos][-2]` 会越界，所以这里选用 11 作为前导 0 标志

其它的都是模板就不多赘述了



### 代码

``` c++
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;
const int MAX_N = 20;
int a[MAX_N];
int dp[MAX_N][20]; // dp[pos][pre]保存从低到高第pos位数且前一位数为pre的情况数量

// pos:从低到高第几位，pre:前一位上的数字，limit:最高位限制标记
// pre为11表示前一位是前导0
int dfs(int pos, int pre, bool limit)
{
    if (pos < 0)
        return 1;
    if (~dp[pos][pre] && !limit)
        return dp[pos][pre];
    int res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        if (abs(pre - i) < 2) // 与前一位数之差小于2的情况
            continue;
        if (pre == 11 && !i) // 前一位是前导0的情况
            res += dfs(pos - 1, 11, limit && i == a[pos]);
        else
            res += dfs(pos - 1, i, limit && i == a[pos]);
    }
    if (!limit)
        dp[pos][pre] = res;
    return res;
}

int digitalDP(int num)
{
    int len;
    for (len = 0; num; num /= 10)
        a[len++] = num % 10;
    return dfs(len - 1, 11, true);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int a, b;
    cin >> a >> b;
    cout << digitalDP(b) - digitalDP(a - 1) << '\n'; // 差分
    return 0;
}
```

