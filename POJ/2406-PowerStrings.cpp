#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1000000;
char s[MAXN + 10];
int nn[MAXN + 10];

void cal_next(char *a, int len)
{
    int i = 0, j = -1;
    nn[0] = -1;
    while (i < len)
    {
        if (j == -1 || a[i] == a[j])
        {
            nn[++i] = ++j;
        }
        else
            j = nn[j];
    }
}

int main()
{
    while (scanf("%s", s) && s[0] != '.')
    {
        int len = strlen(s);
        cal_next(s, len);
        if (len % (len - nn[len]) == 0)
            printf("%d\n", len / (len - nn[len]));
        else
            printf("1\n");
    }
    return 0;
}
