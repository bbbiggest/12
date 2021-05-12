#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> w(n);
        for (int i = 0; i < n; ++i)
            cin >> w[i];
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (sum + w[i] == x)
            {
                if (i + 1 < n)
                    swap(w[i], w[i + 1]);
                else
                {
                    sum = -1;
                    break;
                }
            }
            sum += w[i];
        }
        if (sum == -1)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
            cout << w[i] << " \n"[i == n - 1];
    }
    cout.flush();
    return 0;
}