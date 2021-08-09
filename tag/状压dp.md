## 状态压缩 DP

有时在搜索中，我们可以将状态**编码**为一个整数，或者给它们定义一个**全序关系**，从而可以把状态当成**下标**来进行**记忆化搜索**

这样将**状态**压缩成一个**整数**的方法就叫做**状态压缩**



### 旅行商问题 (TSP)

> 给定一个 n(2 ≤ n ≤ 15) 个顶点组成的带权有向图的距离矩阵 d(i, j) (0 ≤ d(i, j) ≤ 1000)（ INF 表示没有边）。要求从顶点 0 出发，经过每个顶点恰好一次后再回到顶点 0 。问所经过的边的总权重的最小值是多少？

<img width="149" alt="状压dp_1" src="https://user-images.githubusercontent.com/60065681/128723047-83b7f5a6-9c46-4fbd-8941-7c387344cd47.png">


> 上图的答案为： 22(0 -> 3 -> 4 -> 1 -> 2 -> 0)

旅行商问题是 **NP 困难**的，不过在本题中它的 n 只有 15 ，**数据范围较小**，还是可以求解的

我们可以将已访问过的顶点的集合**编码**为一个整数，然后就可以很方便地进行**记忆化搜索**

设已访问过的顶点的集合为 S ，当前所在顶点为 v ，`dp[S][v]` 表示从 v 出发访问剩余的所有顶点，并最终回到顶点 0 的路径的权重的最小值

则可以使用如下代码进行**记忆化搜索**求解出答案为 `ans = dfs(0, 0)` 

其中 `int dp[1 << MAX_N][MAX_N]` 初始化为 **-1** ，因为有时答案为 0 

``` c++
int dfs(int S, int v)
{
    // 已经搜索过了，直接返回答案即可
    if (dp[S][v] >= 0)
        return dp[S][v];

    // 若已近访问过所有节点并且回到0节点
    if (S == (1 << n) - 1 && v == 0)
        return dp[S][v] = 0;

    int res = INF;
    for (int u = 0; u < n; ++u)
    {
        // 若顶点u尚未被访问
        if (!(S >> u & 1))
            res = min(res, dfs(S | 1 << u, u) + d[v][u]);
    }
    return dp[S][v] = res;
}
```

其**复杂度**为 **O(2<sup>n</sup> n<sup>2</sup>)**



### 轮廓线 dp & 棋盘问题

**轮廓线 dp** 也叫 **插头 dp** ，是基于状压 dp 的一种动态规划

嗯...一般就像下面这个表格这样

<img width="411" alt="table" src="https://user-images.githubusercontent.com/60065681/128722971-a38b7284-53ba-4303-9ba7-ed98211a05ac.png">



黑色的这条就是**轮廓线**，所以叫轮廓线 dp ，然后它的形状很像粉红色的**插头**插到黑色的插座里面 ~~这个确实有点勉强但有的题很像~~，所以也叫插头 dp 

一般对于粉色块来说，它需要考虑的状态就是这几个黑色块里是否已放置东西，所以通常会将所有黑色块**压缩**为一个整数，以供粉色块判断是否能放置

放置问题是状压 dp 中的另一种经典题型，一般可用轮廓线 dp 求解

> 给定一个 nxm 的格子地图，要摆放 k 个物品在地图上，每个棋子占一格，摆放时任意的两个物品不能有公共边，求有多少种可行的摆放方案

我们可以**从左至右**，**从上到下**地摆放棋子，然后像刚刚说的那样进行**递推**

``` c++
for (int i = 0; i < n; ++i)
{
    for (int j = 0; j < m; ++j)
    {
        memset(next, 0, sizeof(next));
        for (int st = 0; st < (1 << n); ++st)
        {
            int nst = (st << 1) % (1 << n); // st的下一个状态
            for (int cnt = 0; cnt <= k; ++cnt)
            {
                next[nst][cnt] += crt[st][cnt]; // (i,j)不放物品的情况
                if (cnt >= k)                   // 是否已放满了k个物品
                    continue;
                if (i && (st & (1 << n))) // (i,j)上方有物品
                    continue;
                if (j && (st & 1)) // (i,j)左边有物品
                    continue;
                next[nst + 1][cnt + 1] += crt[st][cnt]; // (i,j)放物品的情况
            }
        }
        swap(crt, next);
    }
}
```

棋盘问题一般是长方形块放满的问题

![状压dp_2](https://user-images.githubusercontent.com/60065681/128722859-56500471-8bd1-4ee2-8e9d-c6540ecd5dc2.png)


求有多少种放置方案，有时候会有要求某些地方不能放置，不过都可用轮廓线 dp 求解



**一般用状压 dp 求解的问题 n 都不会超过 20**

**一般状压 dp 的复杂度都是 O(2<sup>n</sup> n<sup>2</sup>)** 



### 题单

（ POJ 和 HDU 的题目给出的链接为 vjudge链接）

| 序号 |                             题号                             |                标题                 |   题型    | 难度  | 题解 |
| :--: | :----------------------------------------------------------: | :---------------------------------: | :-------: | :---: | :--: |
|  1   |        [poj2441](https://vjudge.net/problem/POJ-2441)        |          Arrange the Bulls          |  状压 dp  |  ☆☆☆  |  ✿   |
|  2   |        [poj2686](https://vjudge.net/problem/POJ-2686)        |       Traveling by Stagecoach       |  状压 dp  |  ☆☆☆  |  ✿   |
|  3   |        [poj3254](https://vjudge.net/problem/POJ-3254)        |             Corn Fields             | 轮廓线 dp |  ☆☆☆  |  ✿   |
|  4   |     [洛谷P1896](https://www.luogu.com.cn/problem/P1896)      |              互不侵犯               | 轮廓线 dp |  ☆☆☆  |  ✿   |
|  5   |        [poj2411](https://vjudge.net/problem/POJ-2411)        |          Mondriaan's Dream          |  状压 dp  |  ☆☆☆  |  ✿   |
|  6   | [sztu-oj1067](http://10.1.97.60/csuoj/problemset/problem?pid=1067) | Staginner In The Everdistant Utopia | 轮廓线 dp |  ☆☆☆  |  ✿   |
|  7   |  [cf580D](https://codeforces.com/problemset/problem/580/D)   |           Kefa and Dishes           |  状压 dp  |  ☆☆☆  |  ✿   |
|  8   | [cf1313D](https://codeforces.com/problemset/problem/1313/D)  |           Happy New Year            |  状压 dp  |  ☆☆☆  |  ✿   |
|  9   |        [poj2836](https://vjudge.net/problem/POJ-2836)        |        Rectangular Covering         |  状压 dp  | ☆☆☆☆  |  ✿   |
|  10  |        [poj1795](https://vjudge.net/problem/POJ-1795)        |           DNA Laboratory            |  状压 dp  | ☆☆☆☆☆ |  ✿   |

