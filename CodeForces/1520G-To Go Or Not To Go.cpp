// 1520G - To Go Or Not To Go?
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using ll = long long;
const ll INF = (ll)1e18;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, w;
    cin >> n >> m >> w;
    vector<vector<int>> c(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];
    vector<vector<int>> d(n, vector<int>(m, -1));
    auto bfs = [&](int sx, int sy)
    {
        d.assign(n, vector<int>(m, -1));
        queue<P> que;
        que.push(P(sx, sy));
        d[sx][sy] = 0;
        while (!que.empty())
        {
            P p = que.front();
            que.pop();
            int x = p.first, y = p.second;
            for (int k = 0; k < 4; ++k)
            {
                int x2 = x + dx[k];
                int y2 = y + dy[k];
                if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)
                    continue;
                if (c[x2][y2] < 0 || ~d[x2][y2])
                    continue;
                d[x2][y2] = d[x][y] + 1;
                que.push(P(x2, y2));
            }
        }
    };
    bfs(0, 0);
    ll ans = ~d[n - 1][m - 1] ? (ll)d[n - 1][m - 1] * w : INF;
    ll smin = INF, tmin = INF;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (c[i][j] > 0 && ~d[i][j])
                smin = min(smin, (ll)d[i][j] * w + c[i][j]);
    bfs(n - 1, m - 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (c[i][j] > 0 && ~d[i][j])
                tmin = min(tmin, (ll)d[i][j] * w + c[i][j]);
    ans = min(ans, smin + tmin);
    if (ans >= INF)
        ans = -1;
    cout << ans << '\n';
    cout.flush();
    return 0;
}