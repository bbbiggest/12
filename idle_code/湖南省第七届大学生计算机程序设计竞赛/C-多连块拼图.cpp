#include <iostream>
#include <cstring>
using namespace std;
char big[10 + 5][10 + 5], small[10 + 5][10 + 5];
int n, m, xb, yb, xs, ys;
int judge();
void bigfindx();
void smallfindx();
int answer();

int main()
{
    while (scanf("%d%d", &n, &m) == 2 && n)
    {
        memset(big, '\0', sizeof(big));
        memset(small, '\0', sizeof(small));
        for (int i = 0; i < n; i++)
            scanf("%s", big[i]);
        for (int i = 0; i < m; i++)
            scanf("%s", small[i]);
        printf("%d\n", judge());
    }
    return 0;
}

void smallfindx()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (small[i][j] == '*')
            {
                xs = i;
                ys = j;
                return;
            }
        }
    }
}

void bigfindx()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (big[i][j] == '*')
            {
                xb = i;
                yb = j;
                return;
            }
        }
    }
}

int judge()
{
    smallfindx();
    int twice = 2;
    while (twice--)
    {
        bigfindx();
        for (int i = 0; i < m - xs; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (small[xs + i][j] == '*')
                {
                    if (big[xb + i][yb + j - ys] == '*')
                        big[xb + i][yb + j - ys] = '.';
                    else
                        return 0;
                }
            }
        }
    }
    return answer();
}

int answer()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (big[i][j] == '*')
                return 0;
    return 1;
}

//https://vjudge.net/problem/NBUT-1105
