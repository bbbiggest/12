// 洛谷P2602 - 数字计数
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX_N = 20;
int a[MAX_N];
ll dp[MAX_N][20]; // dp[pos][sum]
int Cur; // 当前统计的是哪个数字

// pos:从低到高第几位，sum:在当前位时，Cur在这个数字中出现的次数
// lead:(lead==true)表示前一位为前导0，limit:最高位限制标记
ll dfs(int pos, int sum, bool lead, bool limit)
{
    if (pos < 0)
        return sum;
    if (~dp[pos][sum] && !limit && !lead)
        return dp[pos][sum];
    ll res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        // 当前位于要统计的数字相同时，sum+1，若要统计的是0还需判定当前位非前导0
        if (i == Cur && (Cur || !lead))
            res += dfs(pos - 1, sum + 1, !i && lead, limit && i == a[pos]);
        else // 不同时则不增加sum
            res += dfs(pos - 1, sum, !i && lead, limit && i == a[pos]);
    }
    if (!limit && !lead)
        dp[pos][sum] = res;
    return res;
}

ll digitalDP(ll num)
{
    int len;
    for (len = 0; num; num /= 10)
        a[len++] = num % 10;
    return dfs(len - 1, 0, true, true);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    ll a, b;
    cin >> a >> b;
    for (Cur = 0; Cur < 10; ++Cur) // 当前统计的数字
        cout << digitalDP(b) - digitalDP(a - 1) << ' ';
    return 0;
}