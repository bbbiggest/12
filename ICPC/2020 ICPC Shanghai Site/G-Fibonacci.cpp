// 2020 ICPC Shanghai Site - G. Fibonacci
#include <iostream>
using namespace std;
using ll = long long;
int main()
{
	int n;
	while (cin >> n)
	{
		ll a = n - 3, b = n % 3, c = n / 3;
		ll ans = (a + b) * c / 2;
		ans += (c + 1) * c;
		cout << ans << endl;
	}
	return 0;
}