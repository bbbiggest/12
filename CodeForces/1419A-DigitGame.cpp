#include <iostream>
#include <cstring>
using namespace std;
int judge(char c);
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        char num[1010];
        memset(num, '\0', sizeof(num));
        getchar();
        for (int j = 0; j < n; j++)
        {
            cin >> num[j];
        }
        if (n == 1 || n == 2)
        {
            int ans = 0;
            if (n == 1)
                ans = num[0] - '0';
            else if (n == 2)
                ans = num[1] - '0';
            if (ans % 2 == 0 || ans == 0)
                cout << "2" << endl;
            else
                cout << "1" << endl;
            continue;
        }
        else
        {
            int r1 = 0, r2 = 0, b1 = 0, b2 = 0, e[1010];
            memset(e, 0, sizeof(e));
            for (int j = 0; j < n; j++)
            {
                e[j] = judge(num[j]);
                if (j == 0)
                {
                    if (e[j] == 1)
                        r1++;
                    else
                        r2++;
                }
                else if (j % 2 == 0)
                {
                    if (e[j] == 1)
                        r1++;
                    else
                        r2++;
                }
                else
                {
                    if (e[j] == 1)
                        b1++;
                    else
                        b2++;
                };
            }
            if (n % 2 == 0)
            {
                if (b2 > 0)
                    cout << "2" << endl;
                else
                    cout << "1" << endl;
                continue;
            }
            else
            {
                if (r1 > 0)
                    cout << "1" << endl;
                else
                    cout << "2" << endl;
                continue;
            }
        }
    }
    return 0;
}

int judge(char c)
{
    int j = c - '0';
    if (j % 2 == 0 || j == 0)
        return 2;
    else
        return 1;
}
