#include <iostream>
#include <queue>
#include <map>
using namespace std;
const int MAXH = 1000;
const int MAXW = 1000;
const int MAXN = 9;
const int INF = 0x7FFFFFFF;
char JOI[MAXH + 10][MAXW + 10];
int d[MAXH + 10][MAXW + 10];
int h, w, n;
int sx, sy;
typedef pair<int, int> P;
P goal[MAXN + 10];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs(int k)
{
    queue<P> que;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            d[i][j] = INF;
    que.push(P(sx, sy));
    d[sx][sy] = 0;
    while (que.size())
    {
        P p = que.front();
        que.pop();
        if (p.first == goal[k].first && p.second == goal[k].second)
            break;
        for (int i = 0; i < 4; ++i)
        {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && JOI[nx][ny] != 'X' && d[nx][ny] == INF)
            {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[goal[k].first][goal[k].second];
}

int main()
{
    cin >> h >> w >> n;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> JOI[i][j];
            if (JOI[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if (JOI[i][j] > '0' && JOI[i][j] <= '9')
            {
                int tem = JOI[i][j] - '0';
                goal[tem].first = i;
                goal[tem].second = j;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += bfs(i);
        sx = goal[i].first;
        sy = goal[i].second;
    }
    cout << ans << "\n";
    return 0;
}
