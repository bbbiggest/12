// 2020 ICPC Shanghai Site - M. Gitignore
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int MAX_N = 100 + 10;
unordered_set<string> cant, used;
string ign[MAX_N], nign[MAX_N];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cant.clear();
        used.clear();
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> ign[i];
        for (int i = 0; i < m; ++i)
        {
            cin >> nign[i];
            // 将所有不能忽略的文件夹记录下来
            for (int j = 0; j < nign[i].size(); ++j)
            {
                if (nign[i][j] == '/')
                {
                    string tem = nign[i].substr(0, j + 1);
                    cant.insert(tem);
                }
            }
        }
        int cnt = n; // 先假设忽略所有文件需要忽略n次
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < ign[i].size(); ++j)
            {
                if (ign[i][j] == '/')
                {
                    string tem = ign[i].substr(0, j + 1);
                    if (cant.count(tem)) // 若该文件所在文件夹不能被忽略，则不用减一
                        continue;
                    else if (!used.count(tem)) // 若该文件夹可以忽略且未被忽略，则忽略，但不用减一
                        used.insert(tem);
                    else // 若该文件所在文件夹已被忽略，则跳过，忽略次数减一
                    {
                        cnt--;
                        break;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}