// Random 3 people team
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    string s, tem;
    vector<string> names;
    srand(time(nullptr));
    cout << "Enter all the people who need to team up:\n";
    // 输入所有需组队的人
    cout << "Whether you need to read from file \"member.txt\" ?\nY or N\n";
    // 是否需要从文件"member.txt"中读取
    char c;
    bool isopen = false;
    while (cin >> c)
    {
        if (c == 'N' || c == 'n') // 从键盘输入
        {
            getchar();
            cout << "Please enter:(ctrl+Z is end)\n";
            break;
        }
        else if (c == 'Y' || c == 'y') // 从"member.txt"中读取
        {
            if (freopen("member.txt", "r", stdin))
            {
                isopen = true;
                break;
            }
            else
            {
                cout << "open file error!\n";
                cout << "Whether you need to read from file \"member.txt\" ?\nY or N\n";
                continue;
            }
        }
        else // 重新输入
        {
            cout << "Error!\nPlease re-enter:\n";
            cout << "Whether you need to read from file \"member.txt\" ?\nY or N\n";
            continue;
        }
    }

    while (getline(cin, s))
    {
        stringstream ss(s);
        while (ss >> tem)
            names.push_back(tem);
    }
    if (isopen)
        freopen("CON", "r", stdin);
    random_shuffle(names.begin(), names.end());
    int number = names.size();

    time_t now = time(0);
    char date[100];
    strftime(date, sizeof(date), "%Y/%m/%d-team_results", localtime(&now));

    int teamnum = 0;
    cout.flush();
    freopen("team_results.txt", "w", stdout);
    cout << date << "\n";
    cout << "Team " << ++teamnum << ": ";
    for (int i = 0; i < number; ++i)
    {
        cout << setw(15) << left << names[i] << "\t";
        if ((i + 1) % 3 == 0 && (i + 1) != number)
            cout << "\nTeam " << ++teamnum << ": ";
    }
    cout.flush();
    freopen("CON", "w", stdout);
    cout << "The result has been saved to \"team_results.txt\"\n";
    // 将结果储存至"team_results.txt"，同时也在屏幕上显示
    cout << "The team grouping results are as follows: \n";
    teamnum = 0;
    cout << "Team " << ++teamnum << ": ";
    for (int i = 0; i < number; ++i)
    {
        cout << setw(15) << left << names[i] << "\t";
        if ((i + 1) % 3 == 0 && (i + 1) != number)
            cout << "\nTeam " << ++teamnum << ": ";
    }
    cout.flush();
    return 0;
}
