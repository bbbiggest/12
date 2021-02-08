#include <iostream>
using namespace std;
const int INF = 0x3FFFFFFF;
const int MAX_N = 100010;
int num[MAX_N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    num[0] = num[n + 1] = INF;
    int lb = 1, ub = n;
    while (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;
        cout << "? " << mid << endl;
        cin >> num[mid];
        cout << "? " << mid + 1 << endl;
        cin >> num[mid + 1];
        if (num[mid] < num[mid + 1])
            ub = mid;
        else
            lb = mid + 1;
    }
    cout << "! " << lb << endl;
    cout.flush();
    return 0;
}
