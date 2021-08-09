#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        char num[5 + 10];
        memset(num, '\0', sizeof(num));
        cin >> num;
        int n = strlen(num);
        if (n == 5)
        {
            cout << "3" << endl;
            continue;
        }
        else if (n == 3)
        {
            int one = 0, two = 0;
            if (num[0] == 'o')
                one++;
            if (num[1] == 'n')
                one++;
            if (num[2] == 'e')
                one++;
            if (num[0] == 't')
                two++;
            if (num[1] == 'w')
                two++;
            if (num[2] == 'o')
                two++;
            if (one >= 2)
            {
                cout << "1" << endl;
                continue;
            }
            if (two >= 2)
            {
                cout << "2" << endl;
                continue;
            }
        }
    }
    return 0;
}
