#include <iostream>
#include <vector>
using namespace std;
using P = pair<int, int>;
const int BLACK = 0, WHITE = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<P> cb[2];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cb[(i + j) % 2].push_back(P(i, j));
    for (int t = 0; t < n * n; ++t)
    {
        int a, b, color;
        cin >> a;
        if (a == 1)
        {
            color = (!cb[BLACK].empty() ? BLACK : WHITE);
            b = (!cb[BLACK].empty() ? 2 : 3);
        }
        else if (a == 2)
        {
            color = (!cb[WHITE].empty() ? WHITE : BLACK);
            b = (!cb[WHITE].empty() ? 1 : 3);
        }
        else
        {
            color = (!cb[WHITE].empty() ? WHITE : BLACK);
            b = (!cb[WHITE].empty() ? 1 : 2);
        }
        P coo = cb[color].back();
        cb[color].pop_back();
        cout << b << ' ' << coo.first << ' ' << coo.second << endl;
    }
    return 0;
}