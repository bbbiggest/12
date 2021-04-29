#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > b(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> b[i][j];
        vector<int> p(n * m);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
            return b[i / m][i % m] < b[j / m][j % m];
        });
        vector<vector<int> > ans(n, vector<int>(m));
        for (int i = 0; i < m; ++i)
            ans[p[i] / m][i] = b[p[i] / m][p[i] % m];
        for (int i = m; i < n * m; ++i)
        {
            int row = p[i] / m, res = 0;
            while (ans[row][res])
                res++;
            ans[row][res] = b[row][p[i] % m];
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cout << ans[i][j] << " \n"[j == m - 1];
    }
    cout.flush();
    return 0;
}