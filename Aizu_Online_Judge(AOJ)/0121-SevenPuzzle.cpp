#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
const string goalS = "01234567";
const int MAXS = 50000;
map<string, int> cnt;

void bfs(string s)
{
    queue<string> que;
    que.push(s);
    cnt[s] = 0;
    while (!que.empty())
    {
        string ss = que.front();
        que.pop();
        int pos = ss.find('0');
        string tem;
        if (pos < 4)
        {
            tem = ss;
            swap(tem[pos], tem[pos + 4]);
            if (cnt[tem] == 0)
            {
                que.push(tem);
                cnt[tem] = cnt[ss] + 1;
            }
        }
        else
        {
            tem = ss;
            swap(tem[pos], tem[pos - 4]);
            if (cnt[tem] == 0 && tem != s)
            {
                que.push(tem);
                cnt[tem] = cnt[ss] + 1;
            }
        }
        if (pos != 0 && pos != 4)
        {
            tem = ss;
            swap(tem[pos], tem[pos - 1]);
            if (cnt[tem] == 0 && tem != s)
            {
                que.push(tem);
                cnt[tem] = cnt[ss] + 1;
            }
        }
        if (pos != 3 && pos != 7)
        {
            tem = ss;
            swap(tem[pos], tem[pos + 1]);
            if (cnt[tem] == 0)
            {
                que.push(tem);
                cnt[tem] = cnt[ss] + 1;
            }
        }
    }
}

int main()
{
    bfs(goalS);
    string tem;
    while (getline(cin, tem))
    {
        string s;
        for (int i = 0; i < tem.size(); ++i)
        {
            if (tem[i] != ' ')
                s += tem[i];
        }
        cout << cnt[s] << endl;
    }
    return 0;
}
