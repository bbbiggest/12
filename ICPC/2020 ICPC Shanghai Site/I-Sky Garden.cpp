// 2020 ICPC Shanghai Site - I. Sky Garden
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
const double PI = acos(-1);
int main()
{
    int n, m;
    cin >> n >> m;
    cout << fixed << setprecision(10);
    double sum = 0;
    for (int r = 1; r <= n; ++r)
    {
        double s = 0;
        for (int i = 0; i < 2 * m - 1; ++i)
        {
            for (int j = i + 1; j < 2 * m; ++j)
            {
                int num = min(j - i, 2 * m - j + i);
                sum += min((double)2 * r, num * PI * r / m);
                if (i == 0)
                    s += min((double)2 * r, num * PI * r / m);
            }
        }
        sum += s * (n - r) * 2 * m;
        if (m != 1)
            sum += r * 2 * m;
    }
    for (int i = 1; i <= n - 1; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            sum += (j - i) * 2 * m * 2 * m;
        }
    cout << sum << "\n";
    return 0;
}