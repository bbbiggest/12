#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll f[12][1 << 11];
bool vis[1 << 11];
int main()
{
    int n, m, cnt;
    while (cin >> n >> m && m)
    {
        for (int i = 0; i < (1 << n); ++i)
        {
            vis[i] = true;
            cnt = 0;
            for (int j = 0; j < n; ++j)
            {
                if (i >> j & 1)
                {
                    if (cnt & 1)
                    {
                        vis[i] = false;
                        break;
                    }
                }
                else
                    cnt++;
            }
            if (cnt & 1)
                vis[i] = false;
        }

        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 0; j < (1 << n); ++j)
            {
                for (int k = 0; k < (1 << n); ++k)
                {
                    if ((j & k) == 0 && vis[j | k])
                    {
                        f[i][j] += f[i - 1][k];
                    }
                }
            }
        }
        cout << f[m][0] << '\n';
    }
    return 0;
}
