#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cnt, color;
        int last;
        for (int i = 0; i < n; ++i)
        {
            int tem;
            cin >> tem;
            if (i == 0)
                cnt = color = 1;
            else if (tem == last)
            {
                cnt++;
                color = color > cnt ? color : cnt;
            }
            else if (tem != last)
                cnt = 1;
            last = tem;
        }
        cout << color << endl;
    }
    return 0;
}
