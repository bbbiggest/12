#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        int tem;
        cin >> tem;
        s ^= tem;
    }
    if (n % 2 == 0)
    {
        if (s != 0)
        {
            cout << "NO\n";
            return 0;
        }
        n--;
    }
    cout << "YES\n" << n - 2 << "\n";
    for (int i = 1; i <= n - 2; i += 2)
        cout << i << " " << i + 1 << " " << i + 2 << "\n";
    for (int i = n - 2; i >= 3; i -= 2)
        cout << i - 2 << " " << i - 1 << " " << i << "\n";
    return 0;
}
