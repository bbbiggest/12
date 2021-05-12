#include <bits/stdc++.h>
using namespace std;

bool isSquare(int x)
{
    int y = sqrt(x);
    return y * y == x;
}

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
        if ((n % 2 == 0 && isSquare(n / 2)) || (n % 4 == 0 && isSquare(n / 4)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    cout.flush();
    return 0;
}