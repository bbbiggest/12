// S-Trees, UVa712
// aoapc - Exercise 6-2.
// https://vjudge.net/problem/UVA-712

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    int n;
    int t = 0;
    while (cin >> n && n)
    {
        int num = pow(2, n);
        getchar();
        string s, temp;
        getline(cin, s);
        vector<int> a;
        cin >> temp;
        for (int i = 0; i < num; ++i)
            a.push_back(temp[i] - '0');
        int time;
        cin >> time;
        vector<int> ans;
        for (int i = 0; i < time; ++i)
        {
            cin >> temp;
            int x = 0;
            for (int j = 0, num2 = num / 2; j < n; ++j, num2 /= 2)
                x += (temp[j] - '0') * num2;
            ans.push_back(a[x]);
        }
        cout << "S-Tree #" << ++t << ":\n";
        for (auto i : ans)
            cout << i;
        cout << "\n\n";
    }
    return 0;
}
