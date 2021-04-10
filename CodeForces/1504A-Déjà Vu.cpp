#include <iostream>
#include <string>
using namespace std;

bool isPd(const string &s)
{
    int l = s.size() - 1;
    for (int i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[l - i])
            return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.find_first_not_of('a') > s.size() - 1)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        string a = "a";
        if (!isPd(a + s))
            cout << a + s << '\n';
        else
            cout << s + a << '\n';
    }
    return 0;
}