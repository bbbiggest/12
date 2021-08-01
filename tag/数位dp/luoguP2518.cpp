#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
int p[11], q[11];
int add(int x)
{
    for (; x < 11; x += x & -x)
        ++q[x];
}
int sum(int x)
{
    int r = 0;
    for (; x; x -= x & -x)
        r += q[x];
    return r;
}
int main()
{
    int n, i, c, a;
    long double s = 0, t = 1;
    string str;
    cin >> str;
    n = str.size();
    for (i = n - 1; i >= 0; --i)
    {
        a = str[i] - '0' + 1;
        c = sum(a - 1);
        if (!c)
            t = t * (n - i) / (++p[a]);
        else
        {
            t /= (++p[a]);
            s += t * c;
            t *= (n - i);
        }
        add(a);
    }
    cout << (ll)(s + 0.5);
    return 0;
}