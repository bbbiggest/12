#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 0x3FFFFFFF;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    if (k & 1)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cout << -1 << " \n"[j == m - 1];
        return 0;
    }
    vector<vector<int>> a(n, vector<int>(m - 1)), b(n - 1, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m - 1; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m; ++j)
            cin >> b[i][j];
    vector<vector<int>> crt(n, vector<int>(m));
    for (int h = 0; h < k / 2; ++h)
    {
        vector<vector<int>> nxt(n, vector<int>(m, INF));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (j > 0)
                    nxt[i][j] = min(crt[i][j - 1] + a[i][j - 1], nxt[i][j]);
                if (j + 1 < m)
                    nxt[i][j] = min(crt[i][j + 1] + a[i][j], nxt[i][j]);
                if (i > 0)
                    nxt[i][j] = min(crt[i - 1][j] + b[i - 1][j], nxt[i][j]);
                if (i + 1 < n)
                    nxt[i][j] = min(crt[i + 1][j] + b[i][j], nxt[i][j]);
            }
        }
        swap(crt, nxt);
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cout << crt[i][j] * 2 << " \n"[j == m - 1];
    cout.flush();
    return 0;
}