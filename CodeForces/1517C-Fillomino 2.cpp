#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        ans[i][i] = p[i];
        int cnt = p[i], x = i, y = i;
        while (cnt--)
        {
            ans[x][y] = p[i];
            if (y && !ans[x][y - 1])
                y--;
            else
                x++;
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            cout << ans[i][j] << " \n"[j == i];
    cout.flush();
    return 0;
}