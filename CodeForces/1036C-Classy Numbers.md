## cf1036C - Classy Numbers 题解



### 题目大意

给定 T(1 ≤ T ≤ 10) 组数据，每组两个整数 L, R(1 ≤ L ≤ R ≤ 1×10<sup>18</sup>) ，求 [l, r] 中有多少个”优雅数“，即只包含不超过3个非零数字的数



### 解题思路

数位 dp 模板题

参数除了 **位置 pos** ，**最高位限制 limit** 之外

还要一个记录当前出现了多少个数字的参数 `int cnt` 

如果还没超过 **3 个**的就可以**继续添加**数字，否则只能添加**数字 0** 进去

然后因为**前导 0** 在这题不构成影响，所以可以省掉这个参数

其它的都是**模板**就不多赘述了



### 代码

``` c++
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX_N = 20;
int a[MAX_N];
ll dp[MAX_N][5]; // dp[pos][cnt]

// pos:从低到高第几位，cnt:当前出现的非0数字的个数，limit:最高位限制标记
ll dfs(int pos, int cnt, bool limit)
{
    if (pos < 0)
        return 1;
    if (~dp[pos][cnt] && !limit)
        return dp[pos][cnt];
    ll res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        if (!i) // 0特殊处理一下
            res += dfs(pos - 1, cnt, limit && i == a[pos]);
        else if (cnt < 3) // 如果还没超过3个数字
            res += dfs(pos - 1, cnt + 1, limit && i == a[pos]);
    }
    if (!limit)
        dp[pos][cnt] = res;
    return res;
}

ll digitalDP(ll num)
{
    int len;
    for (len = 0; num; num /= 10)
        a[len++] = num % 10;
    return dfs(len - 1, 0, true);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << digitalDP(r) - digitalDP(l - 1) << '\n'; // 差分
    }
    return 0;
}
```

