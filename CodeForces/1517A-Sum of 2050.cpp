#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n % 2050)
        {
            cout << "-1\n";
            continue;
        }
        int sum = 0;
        for (ll i = n / 2050; i; i /= 10)
            sum += i % 10;
        cout << sum << '\n';
    }
    cout.flush();
    return 0;
}