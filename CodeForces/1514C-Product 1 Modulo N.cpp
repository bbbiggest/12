#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll prod = 1;
    vector<int> v;
    for (int i = 1; i < n; ++i)
    {
        if (__gcd(n, i) == 1)
        {
            v.push_back(i);
            prod = (prod * i) % n;
        }
    }
    if (prod != 1)
        v.pop_back();
    cout << v.size() << '\n';
    for (int x : v)
        cout << x << ' ';
    cout.flush();
    return 0;
}