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
        bool isok = true;
        map<char, int> cnt;
        char last;
        for (int i = 0; i < n; ++i)
        {
            char ch;
            cin >> ch;
            if (cnt[ch] && ch != last)
                isok = false;
            cnt[ch]++;
            last = ch;
        }
        cout << (isok ? "YES\n" : "NO\n");
    }
    cout.flush();
    return 0;
}