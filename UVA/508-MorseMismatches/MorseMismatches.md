# 2020-12-18  P: Morse Mismatches  解题报告（黄腾乐）

## 题目大意
给你一些摩尔斯电码的字典，然后再给你一些电码，并输出这些电码的意思  
假如有多个完全匹配的意思，就输出第一个匹配到的意思加个感叹号  
假如没有完全匹配的，就在原电码后增添或删除一部分，使得有完全匹配的，并输出修改最少的那个  
假如完全不匹配就输出任意哪个都行，没有完全匹配的要加问号  


## 解题思路
先把题目给的几个单词转化为摩尔斯电码并记录下来，然后直接遍历字典匹配每个输入的电码，并记录完全匹配的次数，以此判断是否需要加感叹号，如果没有完全匹配的，就匹配子串。


## 复杂度分析
在最坏情况下，也就是遍历所有的单词，因此时间复杂度为 `O(N)`。


## 算法资料
直接模拟即可


## 心得体会
用map来储存字母单词和对应的摩尔斯电码会比较好处理一些。


## 代码
```c++
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
```
