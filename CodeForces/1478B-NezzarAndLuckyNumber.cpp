#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 9 * 10 + 10;
bool dp[MAX_N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        int q, d;
        cin >> q >> d;
        if (!d)
            d += 10;
        for (int i = d; i <= d * 10; i += 10)
        {
            for (int j = 0; i + j <= d * 10; ++j)
            {
                dp[i + j] |= dp[j];
            }
        }
        while (q--)
        {
            int a;
            cin >> a;
            if (a >= d * 10 || dp[a])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    cout.flush();
    return 0;
}
