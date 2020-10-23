#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct cmp
{
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    string s, tem;
    vector<pair<string, int>> teams;
    srand(time(nullptr));
    cout << "Enter all the people who need to team up:\n";
    // 输入所有需组队的人
    cout << "Whether you need to read from file \"member.txt\" ?\nY or N\n";
    // 是否需要从文件"member.txt"中读取
    char c;
    while (cin >> c)
    {
        if (c == 'N' || c == 'n')
        {
            getchar();
            cout << "Please enter:\n";
            getline(cin, s);
            stringstream ss(s);
            while (ss >> tem)
            {
                int n = rand();
                teams.push_back(pair<string, int>(tem, n));
            }
            break;
        }
        else if (c == 'Y' || c == 'y')
        {
            ifstream in("member.txt");
            if (in.is_open())
            {
                while (!in.eof())
                {
                    getline(in, s);
                    stringstream ss(s);
                    while (ss >> tem)
                    {
                        int n = rand();
                        teams.push_back(pair<string, int>(tem, n));
                    }
                }
                in.close();
                cout << "The results have been stored in \"team.txt\".\n";
                // 结果将储存在"team.txt"中
                // 因为好像显示不了中文，所以默认储存于文件中
                sort(teams.begin(), teams.end(), cmp());
                int numbers = teams.size(), teamnums = 0;
                ofstream out("team.txt");
                out << "Team " << ++teamnums << ": ";
                for (int i = 0; i < numbers; ++i)
                {
                    out << teams[i].first << "\t";
                    if ((i + 1) % 3 == 0 && (i + 1) != numbers)
                        out << "\nTeam " << ++teamnums << ": ";
                }
                out.close();
                return 0;
            }
            else
            {
                cout << "open file error!\n";
                cout << "Whether you need to read from file \"member.txt\" ?\nY or N\n";
                continue;
            }
        }
        else
        {
            cout << "Error!\nPlease re-enter:\n";
            cout << "Whether you need to read from file \"member.txt\" ?\nY or N\n";
            continue;
        }
    }
    sort(teams.begin(), teams.end(), cmp());
    int number = teams.size();
    cout << "Whether to store team results to \"team.txt\" ?\nY or N\n";
    //是否将组队结果储存至“team.txt”
    while (cin >> c)
    {
        int teamnum = 0;
        if (c == 'N' || c == 'n')
        {
            cout << "Team " << ++teamnum << ": ";
            for (int i = 0; i < number; ++i)
            {
                cout << teams[i].first << "\t";
                if ((i + 1) % 3 == 0 && (i + 1) != number)
                    cout << "\nTeam " << ++teamnum << ": ";
            }
            break;
        }
        else if (c == 'Y' || c == 'y')
        {
            ofstream out("team.txt");
            out << "Team " << ++teamnum << ": ";
            for (int i = 0; i < number; ++i)
            {
                out << teams[i].first << "\t";
                if ((i + 1) % 3 == 0 && (i + 1) != number)
                    out << "\nTeam " << ++teamnum << ": ";
            }
            out.close();
            break;
        }
        else
        {
            cout << "Error!\nPlease re-enter:\n";
            cout << "Whether to store team results to \"team.txt\" ?\nY or N\n";
            continue;
        }
    }
    return 0;
}
