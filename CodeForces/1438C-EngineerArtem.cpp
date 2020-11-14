#include <iostream>
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
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                int tem;
                cin >> tem;
                cout << tem + (tem % 2 != (i + j) % 2) << " \n"[j == m];
            }
    }
    return 0;
}
