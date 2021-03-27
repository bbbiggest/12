#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        if (k == 0)
        {
            cout << "YES\n";
            continue;
        }
        else if (2 * k == n)
        {
            cout << "NO\n";
            continue;
        }
        bool okk = true;
        for (int i = 0; i < k; ++i)
        {
            if (s[i] != s[n - 1 - i])
            {
                okk = false;
                cout << "NO\n";
                break;
            }
        }
        if (okk)
            cout << "YES\n";
    }
    return 0;
}