#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        long long ans = 0;
        for (int i = 0; i * 2 < n; ++i)
            for (int j = 0; j * 2 < m; ++j)
            {
                vector<int> med{a[i][j]};
                if (i != n - i - 1)
                    med.push_back(a[n - i - 1][j]);
                if (j != m - j - 1)
                    med.push_back(a[i][m - j - 1]);
                if (i != n - i - 1 && j != m - j - 1)
                    med.push_back(a[n - i - 1][m - j - 1]);
                sort(med.begin(), med.end());
                int x = med[(med.size() - 1) / 2];
                for (auto y : med)
                    ans += abs(x - y);
            }
        cout << ans << "\n";
    }
    return 0;
}

// https://codeforces.com/contest/1422/problem/B
