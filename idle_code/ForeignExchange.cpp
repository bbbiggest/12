// Foreign Exchange, UVa10763
// aoapc - Exercise 5-4.
// https://vjudge.net/problem/UVA-10763

#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (cin >> n && n)
    {
        map<int, int> school;
        for (int i = 0, out, into; i < n; ++i)
        {
            cin >> out >> into;
            school[out]--;
            school[into]++;
        }
        bool ok = true;
        for (map<int, int>::iterator it = school.begin(); it != school.end(); ++it)
        {
            if (it->second)
            {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
