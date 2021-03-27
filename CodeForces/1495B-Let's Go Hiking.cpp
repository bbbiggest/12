#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &x : p)
        cin >> x;
    vector<int> l(n), r(n);
    for (int i = 1; i < n; i++)
        l[i] = p[i] > p[i - 1] ? l[i - 1] + 1 : 0;
    for (int i = n - 2; i >= 0; i--)
        r[i] = p[i] > p[i + 1] ? r[i + 1] + 1 : 0;
    int s = max_element(l.begin(), l.end()) - l.begin();
    bool win = true;
    for (int i = 0; i < n; i++)
    {
        if (i != s && max(l[i], r[i]) >= l[s])
        {
            win = false;
            break;
        }
    }
    cout << (win && l[s] == r[s] && l[s] % 2 == 0) << "\n";
    cout.flush();
    return 0;
}