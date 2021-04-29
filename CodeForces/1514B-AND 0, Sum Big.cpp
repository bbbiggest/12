#include <iostream>
using namespace std;
using ll = long long;
const int M = (int)1e9 + 7;

ll mod_pow(ll x, ll n, ll mod)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << mod_pow(n, k, M) << '\n';
    }
    cout.flush();
    return 0;
}