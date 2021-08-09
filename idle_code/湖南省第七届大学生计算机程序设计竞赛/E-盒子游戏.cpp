#include <iostream>
#include <cstring>
using namespace std;
int bwin[100];
int main()
{
    memset(bwin, 0, sizeof(bwin));
    int n;
    for (n = 1, bwin[0] = 3; bwin[n - 1] < 1e+9; n++)
        bwin[n] = bwin[n - 1] + bwin[n - 1] + 1;
    int t;
    while (scanf("%d", &t))
    {
        if (t == 0)
            break;
        int judge = 1;
        for (int i = 0; i < n; i++)
        {
            if (t == bwin[i])
            {
                judge = 0;
                printf("Bob\n");
                break;
            }
        }
        if (judge)
            printf("Alice\n");
    }
    return 0;
}

//https://vjudge.net/contest/30744#problem/E
