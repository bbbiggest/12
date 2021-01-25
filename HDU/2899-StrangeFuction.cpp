#include <cstdio>
#include <cmath>
const int INF = 101;
double Y;

double F(double x)
{
    double num = 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * x * x - Y * x;
    return num;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lf", &Y);
        double lb = 0, ub = INF;
        for (int i = 0; i < 100; ++i)
        {
            double mid_l = lb + (ub - lb) / 3, mid_r = lb + (ub - lb) / 3 * 2;
            if (F(mid_l) > F(mid_r))
                lb = mid_l;
            else
                ub = mid_r;
        }
        printf("%.4f\n", F(lb));
    }
    return 0;
}
