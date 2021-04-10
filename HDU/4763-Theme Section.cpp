#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ull = unsigned long long;
const ull B = 100000007;

bool contain(string a, string b)
{
    if (a.size() > b.size())
        swap(a, b);
    int al = a.size(), bl = b.size();
    ull t = 1;
    for (int i = 0; i < al; ++i)
        t *= B;
    ull ah = 0, bh = 0;
    for (int i = 0; i < al; ++i)
        ah = ah * B + a[i];
    for (int i = 0; i < al; ++i)
        bh = bh * B + b[i];
    for (int i = 0; i + al <= bl; ++i)
    {
        if (ah == bh)
            return true;
        if (i + al < bl)
            bh = bh * B + b[i + al] - b[i] * t;
    }
    return false;
}

int overlap(string a, string b)
{
    int al = a.size(), bl = b.size();
    int ans = 0;
    ull ah = 0, bh = 0, t = 1;
    for (int i = 1; i <= min(al, bl); ++i)
    {
        ah = ah + a[al - i] * t;
        bh = bh * B + b[i - 1];
        if (ah == bh)
            ans = i;
        t *= B;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.size() < 3)
        {
            cout << "0\n";
            continue;
        }
        int len = overlap(s.substr(s.size() / 2), s.substr(0, s.size() / 2));
        if (len == 0)
        {
            cout << "0\n";
            continue;
        }
        string ss = s.substr(1, s.size() - 2);
        while (len >= 0)
        {
            string ss = s.substr(len, s.size() - len * 2);
            string s3 = s.substr(0, len);
            if (contain(s3, ss))
                break;
            --len;
        }
        cout << len << '\n';
    }
    return 0;
}