#include <iostream>
#include <string>
#include <vector>
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
        vector<string> s(n);
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        int b = m % 3 == 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if ((j - b) % 3 == 0)
                    s[i][j] = 'X';
        for (int i = b; i + 3 < m; i += 3)
        {
            int x = 0;
            if (n > 1 && (s[1][i + 1] == 'X' || s[1][i + 2] == 'X'))
                x = 1;
            s[x][i + 1] = s[x][i + 2] = 'X';
        }
        for (int i = 0; i < n; ++i)
            cout << s[i] << "\n";
    }
    cout.flush();
    return 0;
}