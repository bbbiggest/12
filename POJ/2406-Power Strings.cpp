// KMP or Hash

// KMP
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 1000000 + 10;
char s[MAX_N];
int NN[MAX_N];

void buildNext(char *ptr, int plen)
{
    NN[0] = -1;
    for (int i = 0, j = -1; i < plen;)
    {
        if (j < 0 || ptr[i] == ptr[j])
        {
            i++;
            j++;
            NN[i] = (ptr[i] != ptr[j]) ? j : NN[j];
        }
        else
            j = NN[j];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> s && s[0] != '.')
    {
        int len = strlen(s);
        buildNext(s, len);
        if (len % (len - NN[len]) == 0)
            cout << len / (len - NN[len]) << '\n';
        else
            cout << "1\n";
    }
    cout.flush();
    return 0;
}

// Hash
#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ull;
const ull B = 100000007;
const int MAX_N = 1e6 + 10;
ull t[MAX_N] = {1};
ull Hash[MAX_N];
int main()
{
    for (int i = 1; i < MAX_N; ++i)
        t[i] = t[i - 1] * B;
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s && s[0] != '.')
    {
        Hash[0] = 0;
        for (int i = 1; i <= s.size(); ++i)
            Hash[i] = Hash[i - 1] * B + s[i - 1];
        int len = 1;
        while (len < s.size())
        {
            if (len > 1 && s.size() % len)
            {
                len++;
                continue;
            }
            int cnt = 0;
            for (int i = len; i <= s.size(); i += len)
            {
                if (Hash[i] - Hash[i - len] * t[len] == Hash[len])
                    cnt++;
                else
                    break;
            }
            if (cnt >= s.size() / len)
                break;
            len++;
        }
        cout << s.size() / len << '\n';
    }
    cout.flush();
    return 0;
}