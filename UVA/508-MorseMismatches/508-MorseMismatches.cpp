#include <iostream>
#include <string>
#include <map>
using namespace std;
const int INF = 0x3FFFFFFF;
typedef map<string, string> M; // 用M替换方便一些

int main()
{
    map<char, string> alp; // 存每个数字字母对应的摩尔斯电码
    char ch;
    string tem;
    while (cin >> ch && ch != '*')
    {
        cin >> tem;
        alp[ch] = tem;
    }
    M words; // 先求每个单词对应的摩尔斯电码
    while (cin >> tem && tem[0] != '*')
    {
        words[tem] = "";
        int l = tem.size();
        for (int i = 0; i < l; ++i)
            words[tem] += alp[tem[i]];
    }
    while (cin >> tem && tem[0] != '*') // 匹配每个摩尔斯电码, 直接遍历words即可
    {
        int cnt = 0;
        for (M::iterator it = words.begin(); it != words.end(); ++it) // M是上面typedef替换的那个
        {
            if (it->second == tem)
            {
                if (cnt >= 1) // 第二次匹配到时，输出感叹叹然后打断循环
                {
                    cout << "!";
                    break;
                }
                if (!cnt++) // 输出第一个匹配到的单词
                    cout << it->first;
            }
        }
        if (cnt)
        {
            cout << "\n";
            continue; // 匹配到了就直接下一个
        }
        // 比较哪个比较接近
        string res;
        cnt = INF; // 给cnt一个较大的值
        for (M::iterator it = words.begin(); it != words.end(); ++it)
        {
            string big = tem; // big用来存放长一点的电码
            string small = it->second;
            if (big.size() == small.size()) // 无法满足题目所说的，在原电码后增加或删减一部分后相同
                continue;
            if (big.size() < small.size())
                swap(big, small);
            if (small == big.substr(0, small.size())) // 在长电码中选取与短电码长度相同的前缀，并进行比较
                if (big.size() - small.size() < cnt)  // 如果匹配到修改量更少的电码
                {
                    cnt = big.size() - small.size();
                    res = it->first;
                }
        }
        cout << res << "?\n";
    }
    return 0;
}

// ..... ..--- ------
