#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, vector<int>> point;
        int x, y;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            point[y].push_back(x);
        }
        int mid;
        bool flag = false, tex = true;
        for (map<int, vector<int>>::iterator it = point.begin(); it != point.end(); ++it)
        {
            int sum = 0, s = it->second.size();
            for (int i = 0; i < s; ++i)
                sum += (it->second)[i];
            sum /= s;
            if (tex)
            {
                tex = false;
                mid = sum;
            }
            else if (sum != mid)
            {
                cout << "NO\n";
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        cout << "YES\n";
    }
    return 0;
}
