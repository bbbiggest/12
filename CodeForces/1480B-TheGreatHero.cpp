#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 500010;
struct monster
{
    int aa, bb;
};
monster mm[MAX_N];

bool comp(const monster &m1, const monster &m2)
{
    return m1.aa < m2.aa;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, n;
        cin >> A >> B >> n;
        for (int i = 0; i < n; ++i)
            cin >> mm[i].aa;
        for (int i = 0; i < n; ++i)
            cin >> mm[i].bb;
        sort(mm, mm + n, comp);
        int i, cnt;
        for (i = 0; B >= 1 && i < n; ++i)
        {
            int hm = (mm[i].bb - 1) / A + 1;
            int hh = (B - 1) / mm[i].aa + 1;
            cnt = min(hm, hh);
            B -= cnt * mm[i].aa;
        }
        if (i == n && (cnt * A >= mm[n - 1].bb))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    cout.flush();
    return 0;
}
