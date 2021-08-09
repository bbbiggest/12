## poj2411 - Mondriaan's Dream 题解



### 题目大意

给定一个 *h*×*w*(1<=h,w<=11) 的矩形，然后用 *1*×*2* 的砖块将其填满，求一共有多少种方法，若无法填满则输出 0 



### 解题思路

铺砖问题，轮廓线 dp

从左到右从上到下开始放置砖块，所以只需要考虑上面的和左面的，状态只需记录一行即可

如下图所示

<img width="392" alt="poj2411_1" src="https://user-images.githubusercontent.com/60065681/128756249-23207576-99f9-4973-8eda-d8a0a299b187.png">


将图中黑色部分压缩为一个整数作为状态

`dp[crt][S]` 表示当前行的状态为S时的方案数

用了滚动数组节约内存

记得开 long long



### 代码

``` c++
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX_N = 11;
ll dp[2][1 << MAX_N]; // 滚动数组，dp[crt][S]表示当前行状态为S时的方案数
int main()
{
    int h, w;
    while (cin >> h >> w && h)
    {
        memset(dp, 0, sizeof(dp));
        ll *crt = dp[0], *nxt = dp[1];
        crt[0] = 1;
        for (int i = h - 1; i >= 0; --i)
        {
            for (int j = w - 1; j >= 0; --j)
            {
                for (int used = 0; used < 1 << w; ++used)
                {
                    if (used >> j & 1)
                    {
                        // 不需要在 (i, j) 中放置砖块
                        nxt[used] = crt[used & ~(1 << j)];
                    }
                    else
                    {
                        ll res = 0;
                        // 横着放
                        if (j + 1 < w && !(used >> (j + 1) & 1))
                            res += crt[used | 1 << (j + 1)];
                        // 竖着放
                        if (i + 1 < h)
                            res += crt[used | 1 << j];
                        nxt[used] = res;
                    }
                }
                swap(crt, nxt);
            }
        }
        cout << crt[0] << '\n';
    }
    return 0;
}
```

