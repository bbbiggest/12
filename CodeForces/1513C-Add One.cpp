#include <iostream>
#include <string>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;
const int MAX_M = 200000 + 10;
int dp[MAX_M][10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 10; ++i)
        dp[0][i] = 1;
    for (int i = 1; i <= MAX_M; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (j < 9)
                dp[i][j] = dp[i - 1][j + 1];
            else
                dp[i][j] = ((ll)dp[i - 1][0] + dp[i - 1][1]) % MOD;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        int m;
        cin >> n >> m;
        ll ans = 0;
        for (int i = 0; i < n.size(); ++i)
            ans = (ans + dp[m][n[i] - '0']) % MOD;
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}