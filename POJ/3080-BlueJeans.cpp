#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int MAXM = 11;
const int LEN = 60;
string DNA[MAXM];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i)
            cin >> DNA[i];
        string ans = "no significant commonalities";
        for (int n = 3; n <= LEN; ++n)
        {
            for (int i = 0; i <= LEN - n; ++i)
            {
                string tem = DNA[0].substr(i, n);
                bool flag = true;
                for (int j = 1; j < m; ++j)
                {
                    if (DNA[j].find(tem) == string::npos)
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    continue;
                else
                {
                    if (ans == "no significant commonalities")
                        ans = tem;
                    else if (ans.size() < tem.size())
                        ans = tem;
                    else if (ans.size() == tem.size())
                        ans = ans < tem ? ans : tem;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
