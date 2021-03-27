#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int MAX_N = 10010;
unordered_set<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    int t;
    cin >> t;
    while (t--)
    {
        cout.flush();
        s.clear();
        int n, k;
        cin >> n >> k;
        int ma = -1;
        for (int i = 0; i < n; ++i)
        {
            int tem;
            cin >> tem;
            s.insert(tem);
            if (tem > ma)
                ma = tem;
        }
        int me = 0;
        while (s.count(me))
            me++;
        if (me > ma)
        {
            cout << s.size() + k << "\n";
            continue;
        }
        bool okk = false;
        for (int i = 0; i < k; ++i)
        {
            int a = (me + ma) / 2.0 + 0.5;
            if (s.count(a))
                break;
            s.insert(a);
            ma = max(ma, a);
            while (s.count(me))
                me++;
            if (me > ma)
            {
                cout << s.size() + k - i - 1 << "\n";
                okk = false;
                break;
            }
        }
        if (!okk)
            cout << s.size() << "\n";
    }
    cout.flush();
    return 0;
}