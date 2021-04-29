#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool okk = false;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            int b = sqrt((double)a);
            if (!okk & b * b != a)
                okk = true;
        }
        cout << (okk ? "YES\n" : "NO\n");
    }
    return 0;
}