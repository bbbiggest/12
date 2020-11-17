#include <iostream>
using namespace std;
const int MAXW = 20;
const int MAXH = 20;
char tile[MAXH + 10][MAXW + 10];
int ans = 0;
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};

void dfs(int i, int j)
{
    if (tile[i][j] == '#')
        return;
    if (tile[i][j] == '.')
    {
        ans++;
        tile[i][j] = '#';
    }
    for (int k = 0; k < 4; ++k)
        dfs(i + x[k], j + y[k]);
}

int main()
{
    int w, h;
    while (cin >> w >> h && w && h)
    {
        int ix, iy;
        ans = 1;
        for (int i = 0; i <= h + 1; ++i)
        {
            for (int j = 0; j <= w + 1; ++j)
            {
                if (i == 0 || j == 0 || i == h + 1 || j == w + 1)
                {
                    tile[i][j] = '#';
                    continue;
                }
                cin >> tile[i][j];
                if (tile[i][j] == '@')
                {
                    ix = i;
                    iy = j;
                }
            }
        }
        dfs(ix, iy);
        cout << ans << "\n";
    }
    return 0;
}
