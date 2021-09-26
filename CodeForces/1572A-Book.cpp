#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> deg(n);
        vector<vector<int>> G(n);
        for (int i = 0; i < n; ++i)
        {
            int k;
            cin >> k;
            while (k--)
            {
                int a;
                cin >> a;
                G[a - 1].push_back(i);
                deg[i]++;
            }
        }

        int cnt = 0, ans = 0;
        set<int> rec;
        for (int i = 0; i < n; ++i)
            if (!deg[i])
                rec.insert(i);
        while (!rec.empty())
        {
            ans++;
            int c = 0;
            while (true)
            {
                auto it = rec.lower_bound(c);
                if (it == rec.end())
                {
                    break;
                }
                c = *it;
                cnt++;
                for (int x : G[c])
                {
                    if (--deg[x] == 0)
                        rec.insert(x);
                }
                rec.erase(it);
            }
        }
        if (cnt != n)
            ans = -1;
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}