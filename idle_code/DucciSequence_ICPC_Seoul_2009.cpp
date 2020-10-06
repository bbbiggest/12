Ducci Sequence, ACM/ICPC Seoul 2009, UVa1594
// https://vjudge.net/problem/UVA-1594

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
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
        vector<int> seq, zero(n, 0);
        for (int i = 0, a; i < n; ++i)
        {
            cin >> a;
            seq.push_back(a);
        }
        set<vector<int>> jud;
        int flag = 0;
        while (!flag)
        {
            if (seq == zero)
                flag = 1;
            else if (jud.find(seq) != jud.end())
                flag = 2;
            else
            {
                jud.insert(seq);
                vector<int> temp(n);
                for (int i = 0; i < n; ++i)
                    temp[i] = abs(seq[i] - seq[(i + 1) % n]);
                seq = temp;
            }
        }
        if (flag == 1)
            cout << "ZERO\n";
        else if (flag == 2)
            cout << "LOOP\n";
    }
    return 0;
}
