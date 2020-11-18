#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXX = 300;
const int MAXY = 300;
const int MAXT = 1000 + 10;
const int MAXXY = (MAXX + 10) * (MAXY + 10);
int lattice[MAXX + 10][MAXY + 10];
int t[MAXX + 10][MAXY + 10];
typedef pair<int, int> P;
const int dx[5] = {1, 0, -1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};

int bfs()
{
    if (lattice[0][0] == 0)
        return -1;
    queue<P> que;
    fill(t[0], t[0] + MAXXY, MAXT);
    que.push(P(0, 0));
    t[0][0] = 0;
    while (que.size())
    {
        P p = que.front();
        que.pop();
        if (lattice[p.first][p.second] == MAXT)
            return t[p.first][p.second];
        for (int i = 0; i < 4; ++i)
        {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (nx >= 0 && nx < MAXX + 5 && ny >= 0 && ny < MAXY + 5)
                if (t[nx][ny] == MAXT && t[p.first][p.second] + 1 < lattice[nx][ny])
                {
                    que.push(P(nx, ny));
                    t[nx][ny] = t[p.first][p.second] + 1;
                }
        }
    }
    return -1;
}

int main()
{
    int m;
    scanf("%d", &m);
    fill(lattice[0], lattice[0] + MAXXY, MAXT);
    for (int i = 0; i < m; ++i)
    {
        int x, y, t;
        scanf("%d%d%d", &x, &y, &t);
        for (int k = 0; k < 5; ++k)
        {
            if (x + dx[k] >= 0 && y + dy[k] >= 0)
                if (lattice[x + dx[k]][y + dy[k]] > t)
                    lattice[x + dx[k]][y + dy[k]] = t;
        }
    }
    printf("%d\n", bfs());
    return 0;
}
