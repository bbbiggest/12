#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string a, b;
        cin >> n >> a >> b;
        a.push_back('#');
        b.push_back('#');
        int cnt = 0;
        bool isok = true;
        for (int i = 0; i < n; ++i)
        {
            cnt += (a[i] == '1' ? 1 : -1);
            if ((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && cnt)
            {
                isok = false;
                break;
            }
        }
        cout << (isok ? "YES\n" : "NO\n");
    }
    return 0;
}