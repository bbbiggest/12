#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 100000;
int seq[MAXN + 10];
long long subsum[MAXN + 10];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        memset(subsum, 0, sizeof(subsum));
        for (int i = 1; i <= n; ++i)
        {
            cin >> seq[i];
            subsum[i] = subsum[i - 1] + seq[i];
        }
        if (subsum[n] < s)
        {
            cout << "0\n";
            continue;
        }
        int elenum = 1 << 30;
        for (int i = 1; subsum[i] + s <= subsum[n]; i++)
        {
            int tem = lower_bound(subsum + i + 1, subsum + n + 1, subsum[i] + s) - subsum; 
            elenum = elenum < (tem - i) ? elenum : (tem - i);
        }
        cout << elenum << "\n";
    }
    return 0;
}
