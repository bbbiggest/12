#include <iostream>
using namespace std;
const int MAXH = 100;
const int MAXW = 100;
char land[MAXH + 10][MAXW + 10];
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};
int h, w;

void dfs(int i, int j, char tree)
{
    if (i < 0 || j < 0 || i >= h || j >= w)
        return;
    if (land[i][j] != tree)
        return;
    land[i][j] = '0';
    for (int k = 0; k < 4; ++k)
    {
        dfs(i + x[k], j + y[k], tree);
    }
}

int main()
{
    while (cin >> h >> w && h && w)
    {
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                cin >> land[i][j];
        int ans = 0;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (land[i][j] != '0')
                {
                    ans++;
                    dfs(i, j, land[i][j]);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
