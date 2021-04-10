#include <iostream>
#include <string>
#include <set>
using namespace std;
typedef unsigned long long ull;
const ull B = 9973;
const char doge[2][10] = {"DOGE", "doge"};
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<ull> d;
    for (int i = 0; i < (1 << 4); ++i)
    {
        ull e = 0;
        for (int j = 0; j < 4; ++j)
        {
            int f = ((1 << j) & i) > 0;
            e = e * B + doge[f][j];
        }
        d.insert(e);
    }

    string tem;
    while (getline(cin, tem))
        s += tem + " ";
    
    int cnt = 0;
    int al = 4, bl = s.size();
    ull t = 1;
    for (int i = 0; i < al; ++i)
        t *= B;
    ull bh = 0;
    for (int i = 0; i < al; ++i)
        bh = bh * B + s[i];
    for (int i = 0; i + al <= bl; ++i)
    {
        if (d.count(bh))
            cnt++;
        if (i + al < bl)
            bh = bh * B + s[i + al] - s[i] * t;
    }
    
    cout << cnt << "\n";
    cout.flush();
    return 0;
}