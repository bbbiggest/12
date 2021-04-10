#include <iostream>
#include <string>
using namespace std;
using ull = unsigned long long;
const ull B = 100000007;

int contain(string a, string b)
{
    int al = a.length(), bl = b.length();
    if (al > bl)
        return false;

    ull t = 1;
    for (int i = 0; i < al; ++i)
        t *= B;

    ull ah = 0, bh = 0;
    for (int i = 0; i < al; ++i)
        ah = ah * B + a[i];
    for (int i = 0; i < al; ++i)
        bh = bh * B + b[i];

    int cnt = 0;
    for (int i = 0; i + al <= bl; ++i)
    {
        if (ah == bh)
        {
            cnt++;
            i += al - 1;
        }
        if (i + al < bl)
            bh = bh * B + b[i + al] - b[i] * t;
    }
    return cnt;
}

int main()
{
    string str, ptr;
    while (cin >> str && str[0] != '#')
    {
        cin >> ptr;
        cout << contain(ptr, str) << '\n';
    }
    return 0;
}