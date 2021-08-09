## 数位 dp

数位 dp 一般的题意是，求某某数字到某某数字中，有多少个数字（包含 / 不包含）某某，或者有多少数字满足某某条件

比如：

+ ”求 1 到 487 中有多少数字不含 6“
+ ”求 813 到 999999876 中有多少个数字包含连续的相同的数字，如 88、7883“

这时候就可以用上数位 dp 了，求解这类题型的核心代码如下：

```c++
const int MAX_N = 20; // 数字的位数，十进制long long的20位也够了，高精度就开大点
int a[MAX_N];
ll dp[MAX_N][2]; // 用 `memset(dp, -1, sizeof(dp));` 初始化为-1，因为有些答案为0

// 记忆化搜索
ll dfs(int pos, int st, bool lead, bool limit)
{
    if (pos < 0) // 搜到数字的最后一位时
        return 1;
    if (~dp[pos][st] && !limit && !lead) // 记忆化，剪枝
        return dp[pos][st];
    ll res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        if (...某个不想要的条件...)
            continue;
        res += dfs(pos - 1, ...某个前置条件, !i && lead, limit && i == a[pos]);
    }
    if (!limit && !lead)
        dp[pos][st] = res; // 记忆化
    return res;
}

ll digitalDP(ll num)
{
    if (num < 0)
        return 0;
    int len;
    for (len = 0; num; num /= 10) // 将每一位上的数字分别存入
        a[len++] = num % 10;
    return dfs(len - 1, 0, true, true);
}

// 高精度
ll digitalDP(string num)
{
    int len = num.size();
    for (int i = 0; i < len; ++i)
        a[i] = num[len - 1 - i] - '0'; // 记得翻转字符串
    return dfs(len - 1, 0, true, true);
}
```

dfs 的参数的具体含义如下：

+ pos 表示当前在第几位（从低到高）
+ lead == true 表示前面都为前导 0 
+ limit == true 表示最高位限制标志，比如最大为 543 ，第一位为 5 ，则搜索到第二位时 limit == true
+ st 表示某种状态

其它的一些可视题目要求加进去，比如 `int pre` 表示前面的那位数字；dp 的维数也视具体题意增加，一般两维即可，分别表示 `dp[pos][st]` 。只要你愿意 & 内存够大，你可以把 dp 的维度和 dfs 的参数一一对应，即 `ll dp[20][2][2][2]; // dp[pos][st][lead][limit]` ，这样时间上可能还快一点，时间与空间的取舍



**举个例子：**

+ 比如题目要求数字中不能含有 9 ，那就可以删去 st 参数，只需将 if 语句写为 `if (i == 9) continue;` 即可。

+ 又比如题目要求不能出现 89 ，那就需要 pre 参数或者 st 参数，记录上一个数字或者记录是否前一位数字是 8 ，即：

  ``` c++
  // st 参数
  {
  	...
      if (st && i == 9)
          continue;
      res += dfs(pos - 1, i == 8, ...);
  	...
  }
  ```
  
  ``` c++
  // pre 参数
  ll dp[20][20];
  ll dfs(int pos, int pre, bool lead, bool limit)
  {
      ...
      if (~dp[pos][pre] && !limit && !lead)
          return dp[pos][pre];
      ...
      {
          if (pre == 8 && i == 9)
              continue;
          res += dfs(..., i, ...);
      }
      ...
  }
  ```
  
  修改时需要将 dp 数组的维度及大小也进行相应的更改
  
+ 假如题目要求的不含有 0 的数字的个数，但不包括前导 0 在内，即 0096 是可以的，但 101 和 40 是不行的，这是就体现出 `bool lead` 参数的作用了，if 语句就改为 `if (!lead && i == 0)` ，即当目前这个不是前导了，且 i 又为 0 时就需跳过。而 dfs 中 `res += dfs(, ..., !i && lead, ...);`  就是只有当前数字为 0 ，且前面的也是前导 0 是，才会继续将参数 `lead == true` 传递下去，只要出现非 0 的数字就取消前导标记。当然假如题目要求包括前导 0 时，这个参数就应当去掉。



### 题单

（ POJ 和 HDU 的题目给出的链接为 vjudge链接）

| 序号 |                             题号                             |       标题        |  题型   | 难度 | 题解 |
| :--: | :----------------------------------------------------------: | :---------------: | :-----: | :--: | :--: |
|  1   |        [hdu3555](https://vjudge.net/problem/HDU-3555)        |       Bomb        | 数位 dp |  ☆☆  |  ✿   |
|  2   |        [hdu2089](https://vjudge.net/problem/HDU-2089)        |      不要62       | 数位 dp |  ☆☆  |  ✿   |
|  3   |     [洛谷 P2657](https://www.luogu.com.cn/problem/P2657)     |     windy 数      | 数位 dp |  ☆☆  |  ✿   |
|  4   |     [洛谷 P2602](https://www.luogu.com.cn/problem/P2602)     |     数字计数      | 数位 dp |  ☆☆  |  ✿   |
|  5   |     [洛谷 P3413](https://www.luogu.com.cn/problem/P3413)     |       萌数        | 数位 dp | ☆☆☆  |  ✿   |
|  6   |        [poj3252](https://vjudge.net/problem/POJ-3252)        |   Round Numbers   | 数位 dp | ☆☆☆  |  ✿   |
|  7   |    [cf55D](http://codeforces.com/problemset/problem/55/D)    | Beautiful numbers | 数位 dp | ☆☆☆  |  ✿   |
|  8   | [cf1036C](https://codeforces.com/problemset/problem/1036/C)  |  Classy Numbers   | 数位 dp | ☆☆☆  |  ✿   |
|  9   |   [cf628D](http://codeforces.com/problemset/problem/628/D)   |   Magic Numbers   | 数位 dp | ☆☆☆☆ |  ✿   |
|  10  | [2020 ICPC Shanghai Site<br>-problem C](https://codeforces.com/gym/102900/problem/C) |    Sum of Log     | 数位 dp | ☆☆☆☆ |  ✿   |


