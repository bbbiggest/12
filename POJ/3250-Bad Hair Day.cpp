#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
const int MAX_N = 80010;
int h[MAX_N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    ll ans = 0;
    stack<int> m;
    m.push(h[0]);
    for (int i = 1; i < n; ++i)
    {
        while (!m.empty() && m.top() <= h[i])
            m.pop();
        ans += m.size();
        m.push(h[i]);
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}