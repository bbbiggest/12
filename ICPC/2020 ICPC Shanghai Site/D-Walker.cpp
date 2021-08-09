// 2020 ICPC Shanghai Site - D. Walker
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
double n, p1, v1, p2, v2;

double f(double s, double v, double t)
{
    if (v * t < s)
        return 0;
    // 假设这段路s示意图如右：0-----s----e （0到s点长度为s，e点为路另一端的终点）
    // 如果时间t内没能走完s则直接返回0，不计数，让另一个人努力去
    // 在能把自己该走的路s走完的基础上，分为3种情况的走法
    // 1. 从s往0方向走(0---<-s)，刚好走到s或者走到0点后折返的距离还在0到s之间
    //    即只能覆盖0到s这段路
    // 2. 从s往0方向走，走到0之后折返的距离在s点右边，即(0~~~~~s~>--e)
    //    (~为已经走过的，-为还未覆盖到的路)，其实和1一样，只是走的多覆盖的路比s长
    // 3. 先从s往e的方向走，走到某个位置之后再折返回去把s走完，即(0~<~~~s~~--e)
    //    相当于走了反方向一段后再回去覆盖完0到s的路
    // 选3种情况中选择覆盖了最长的路做返回值
    return max(s, max(v * t - s, s + (v * t - s) / 2));
}

bool C(double t)
{
    // 两人相向走或者相反走能走完
    if (f(p1, v1, t) + f(n - p2, v2, t) > n)
        return true;
    if (f(n - p1, v1, t) + f(p2, v2, t) > n)
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    while (t--)
    {
        cin >> n >> p1 >> v1 >> p2 >> v2;
        // 二分搜最短时间
        double lb = 0, ub = max(2 * n / v1, 2 * n / v2);
        for (int i = 0; i < 100; ++i)
        {
            double mid = lb + (ub - lb) / 2;
            if (C(mid))
                ub = mid;
            else
                lb = mid;
        }
        cout << lb << "\n";
    }
    return 0;
}