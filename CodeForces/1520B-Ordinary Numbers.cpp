#include <bits/stdc++.h>
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
        string s = to_string(n);
        int ans = (s.size() - 1) * 9 + s[0] - '0';
        bool flag = false;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] < s[i - 1])
            {
                flag = true;
                break;
            }
            else if (s[i] > s[i - 1])
                break;
        }
        if (flag)
            ans--;
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}