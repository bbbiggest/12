#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ull;
const ull B = 100000007;
int main()
{
    string s;
    while (cin >> s)
    {
        int l = s.size();
        ull ah = 0, bh = 0, t = 1;
        for (int i = 1; i <= l; ++i)
        {
            ah = ah + s[l - i] * t;
            bh = bh * B + s[i - 1];
            if (ah == bh)
                cout << i << ' ';
            t *= B;
        }
        cout << '\n';
    }
    return 0;
}