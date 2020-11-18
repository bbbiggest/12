#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXH = 20;
const int MAXW = 20;
const int INF = 0x7FFFFFFF;
int square[MAXH + 10][MAXW + 10];
int w, h, ans;
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};

void dfs(int i, int j, int throwtimes, int direction)
{
    if (throwtimes > 10 || throwtimes > ans)
        return;
    while (square[i + x[direction]][j + y[direction]] == 0)
    {
        if (i < 0 || j < 0 || i >= h || j >= w)
            return;
        i += x[direction];
        j += y[direction];
    }
    if (square[i + x[direction]][j + y[direction]] == 1)
    {
        throwtimes++;
        square[i + x[direction]][j + y[direction]] = 0;
        for (int k = 0; k < 4; ++k)
        {
            if (square[i + x[k]][j + y[k]] != 1)
                dfs(i, j, throwtimes, k);
        }
        square[i + x[direction]][j + y[direction]] = 1;
    }
    else if (square[i + x[direction]][j + y[direction]] == 3)
    {
        ans = min(ans, throwtimes);
        return;
    }
}

int main()
{
    while (cin >> w >> h && w && h)
    {
        memset(square, 0, sizeof(square));
        ans = INF;
        int sx, sy;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> square[i][j];
                if (square[i][j] == 2)
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        square[sx][sy] = 0;
        for (int k = 0; k < 4; ++k)
        {
            if (square[sx + x[k]][sy + y[k]] != 1)
                dfs(sx, sy, 1, k);
        }
        if (ans == INF)
            cout << "-1\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
