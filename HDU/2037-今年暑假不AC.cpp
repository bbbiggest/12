#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
pair<int, int> Ti[110];
struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};

int main()
{
    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; ++i)
            cin >> Ti[i].second >> Ti[i].first;
        sort(Ti, Ti + n, cmp());
        int e = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (e <= Ti[i].second)
            {
                ans++;
                e = Ti[i].first;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
