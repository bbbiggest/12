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
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "1\n";
            continue;
        }
        else if (n == 2)
        {
            cout << "-1\n";
            continue;
        }
        int n2 = n * n;
        int l = n2 - n2 / 2;
        queue<int> black, white;
        for (int i = 1; i <= l; ++i)
            black.push(i);
        for (int i = l + 1; i <= n2; ++i)
            white.push(i);
        for (int i = 1; i <= n2; ++i)
        {
            if (i & 1)
            {
                cout << black.front();
                black.pop();
            }
            else
            {
                cout << white.front();
                white.pop();
            }
            cout << " \n"[i % n == 0];
        }
    }
    cout.flush();
    return 0;
}