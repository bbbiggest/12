#include <iostream>
#include <cstring>
using namespace std;
int64_t money[32768 + 10];
int main()
{
    memset(money, 0, sizeof(money));
    money[0] = 1;
    for (int i = 1; i <= 3; ++i)
        for (int j = i; j < 32768; ++j)
            money[j] = money[j] + money[j - i];
    int n;
    while (cin >> n && n)
        cout << money[n] << "\n";
    return 0;
}1
