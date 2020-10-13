#include <iostream>
#include <cstring>
using namespace std;
int peo[200];
int main()
{
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) == 3 && n && m && k)
    {
        memset(peo, 0, sizeof(peo));
        for (int i = 0; i < n; ++i)
            peo[i] = i + 1;
        for (int i = n - 1, j = n; i > 1; i--, j++)
            peo[j] = i;
        int num = 1;
        for (int stop = 0, coun = 0; coun != k; stop++, num++)
        {
            if (stop > 2 * n - 3)
                stop = 0;
            int temp = num;
            bool seven = false;
            if (temp % 7 == 0)
                seven = true;
            else
            {
                while (temp)
                {
                    if (temp % 10 == 7)
                    {
                        seven = true;
                        break;
                    }
                    temp /= 10;
                }
            }
            if (seven && peo[stop] == m)
                coun++;
        }
        cout << num - 1 << endl;
    }
    return 0;
}
