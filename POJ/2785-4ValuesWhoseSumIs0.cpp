#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 4000 + 10;
int A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int APB[MAXN * MAXN], CPD[MAXN * MAXN]; // A plus B, C plus D.
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                APB[i * n + j] = A[i] + B[j];
                CPD[i * n + j] = C[i] + D[j];
            }
        }
        sort(CPD, CPD + n * n);
        for (int i = 0; i < n * n; ++i)
        {
            int L = 0, R = n * n - 1;
            while (L <= R)
            {
                int mid = L + (R - L) / 2;
                if (CPD[mid] == -APB[i])
                {
                    cnt++;
                    for (int j = mid - 1; j >= 0; j--)
                    {
                        if (CPD[j] != -APB[i])
                            break;
                        cnt++;
                    }
                    for (int j = mid + 1; j < n * n; ++j)
                    {
                        if (CPD[j] != -APB[i])
                            break;
                        cnt++;
                    }
                    break;
                }
                else if (CPD[mid] < -APB[i])
                    L = mid + 1;
                else
                    R = mid - 1;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
