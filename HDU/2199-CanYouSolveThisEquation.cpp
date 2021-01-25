#include <cstdio>
const int INF = 101;
const int MAX_K = 807020306;
double K;
bool C(double x)
{
    double num = 0;
    num = 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6;
    return num <= K;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lf", &K);
        if (K < 6 || K > MAX_K)
        {
            printf("No solution!\n");
            continue;
        }
        double lb = 0, ub = INF;
        for (int i = 0; i < 100; ++i)
        {
            double mid = (lb + ub) / 2;
            if (C(mid))
                lb = mid;
            else
                ub = mid;
        }
        printf("%.4f\n", ub);
    }
    return 0;
}
