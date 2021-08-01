#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int M = (int)1e9 + 7;
ll a[1001], dp[1001][10][2];

int dfs(int pos, int pre, int per, int t, int k, bool flag)
{
    if (pos <= 0)
        return t;
    if (!flag && dp[pos][pre][t] != -1)
        return dp[pos][pre][t];
    int end = flag ? a[pos] : 9;
    int ret = 0;
    for (int i = 0; i <= end; i++)
        ret = (ret + dfs(pos - 1, i, k ? pre : -1, t || ((i == pre) && k) || ((i == per) && k), k || (i != 0), flag && (end == i)) % M) % M;
    if (!flag && k && per != -1)
        dp[pos][pre][t] = ret;
    return ret;
}
int digitalDP(string s)
{
    int len = 0, slen = s.size() - 1;
    while (slen >= 0)
        a[++len] = s[slen] - '0', slen--;
    while (!a[len])
        len--;
    memset(dp, -1, sizeof(dp));
    return dfs(len, -1, -1, 0, 0, 1);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int k = 1;
    int l = s1.size();
    while (s1[l - k] == '0' && l > k)
        s1[l - k] = '9', k++;
    s1[l - k] -= 1;
    cout << (digitalDP(s2) - digitalDP(s1) + M) % M << '\n';
    return 0;
}
