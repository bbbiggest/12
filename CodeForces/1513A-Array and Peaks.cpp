#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k > (n - 1) / 2)
        {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << i << ' ';
            if (k)
            {
                cout << n << ' ';
                n--;
                k--;
            }
        }
        cout << '\n';
    }
    return 0;
}