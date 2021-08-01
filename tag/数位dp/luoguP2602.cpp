#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX_N = 20;
int a[MAX_N];
ll dp[MAX_N][20];
int Cur;

ll dfs(int pos, int sum, bool lead, bool limit)
{
    if (pos < 0)
        return sum;
    if (~dp[pos][sum] && !limit && !lead)
        return dp[pos][sum];
    ll res = 0;
    int high = limit ? a[pos] : 9;
    for (int i = 0; i <= high; ++i)
    {
        if (i == Cur && (Cur || !lead))
            res += dfs(pos - 1, sum + 1, !i && lead, limit && i == a[pos]);
        else
            res += dfs(pos - 1, sum, !i && lead, limit && i == a[pos]);
    }
    if (!limit && !lead)
        dp[pos][sum] = res;
    return res;
}

ll digitalDP(ll num)
{
    if (num < 0)
        return 0;
    int len;
    for (len = 0; num; num /= 10)
        a[len++] = num % 10;
    memset(dp, -1, sizeof(dp));
    return dfs(len - 1, 0, true, true);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    for (Cur = 0; Cur < 10; ++Cur)
        cout << digitalDP(b) - digitalDP(a - 1) << ' ';
    return 0;
}