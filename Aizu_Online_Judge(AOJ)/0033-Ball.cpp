#include <iostream>
using namespace std;
const int MAXN = 10;
int ball[MAXN + 10];
int lef[MAXN + 10];
int rig[MAXN + 10];

bool dfs(int k, int l, int r)
{
    if (k == MAXN)
        return true;
    if (ball[k] < lef[l] && ball[k] < rig[r])
        return false;
    if (ball[k] >= lef[l])
    {
        lef[l + 1] = ball[k];
        if (dfs(k + 1, l + 1, r))
            return true;
    }
    if (ball[k] >= rig[r])
    {
        rig[r + 1] = ball[k];
        if (dfs(k + 1, l, r + 1))
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < MAXN; ++i)
            cin >> ball[i];
        lef[0] = rig[0] = 0;
        if (dfs(0, 0, 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
