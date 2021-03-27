#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_N = 100010;
int X[MAX_N], Y[MAX_N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> X, Y;
        for (int i = 0; i < 2 * n; ++i)
        {
            int x, y;
            cin >> x >> y;
            if (x == 0)
                Y.push_back(abs(y));
            else if (y == 0)
                X.push_back(abs(x));
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        double ans = 0;
        for (int i = 0; i < n; ++i)
            ans += sqrt((double)X[i] * X[i] + (double)Y[i] * Y[i]);
        cout << ans << "\n";
    }
    cout.flush();
    return 0;
}