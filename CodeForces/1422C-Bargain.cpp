#include <iostream>
#include <string>
using namespace std;
const long long mod = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    long long n = s.size();
    long long ans = 0, mul = 0, pw = 1;
    for (long long i = n - 1; i >= 0; --i, pw *= 10)
    {
        pw = pw % mod;
        ans = (ans + i * (i + 1) / 2 % mod * pw % mod * (s[i] - '0')) % mod;
        ans = (ans + (s[i] - '0') * mul) % mod;
        mul = (mul + (n - i) * pw) % mod;
    }
    cout << ans << endl;
    return 0;
}

//https://codeforces.com/contest/1422/problem/C
