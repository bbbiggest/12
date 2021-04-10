#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int cnt1 = count(s.begin(), s.end(), '1');
        if (s[0] == '0' || s.back() == '0' || cnt1 % 2)
        {
            cout << "NO\n";
            continue;
        }
        string a, b;
        int k = 0;
        bool f = true;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '1')
            {
                a += (2 * k < cnt1 ? '(' : ')');
                b += a.back();
                k++;
            }
            else
            {
                a += (f ? '(' : ')');
                b += (f ? ')' : '(');
                f = !f;
            }
        }
        cout << "YES\n" << a << '\n' << b << '\n';
    }
    return 0;
}