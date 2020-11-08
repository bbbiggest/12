#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100000;
int ans[MAXN + 10];
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            ans[a]++;
            ans[b + 1]--;
        }
        int t = 0;
        printf("%d", t += ans[1]);
        for (int i = 2; i <= n; i++)
        {
            t += ans[i];
            printf(" %d", t);
        }
        printf("\n");
    }
    return 0;
}
