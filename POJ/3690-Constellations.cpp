// 挑战程序设计竞赛 - p375 例题
#include <iostream>
#include <set>
using namespace std;
const int MAX_T = 100 + 10;
const int MAX_SIZE = 1000 + 10;

typedef unsigned long long ull;

// 输入
int N, M, T, P, Q;
char field[MAX_SIZE][MAX_SIZE];           // 匹配对象
char patterns[MAX_T][MAX_SIZE][MAX_SIZE]; // 匹配模式

ull Hash[MAX_SIZE][MAX_SIZE], tmp[MAX_SIZE][MAX_SIZE];

// 计算a的所有 P x Q 子阵对应的哈希值
void compute_hash(char a[MAX_SIZE][MAX_SIZE], int n, int m)
{
    const ull B1 = 9973;
    const ull B2 = 100000007;

    ull t1 = 1;
    for (int j = 0; j < Q; ++j)
        t1 *= B1;

    // 按行方向计算哈希值
    for (int i = 0; i < n; ++i)
    {
        ull e = 0;
        for (int j = 0; j < Q; ++j)
            e = e * B1 + a[i][j];

        for (int j = 0; j + Q <= m; ++j)
        {
            tmp[i][j] = e;
            if (j + Q < m)
                e = e * B1 - t1 * a[i][j] + a[i][j + Q];
        }
    }

    ull t2 = 1; // B2的P次方
    for (int i = 0; i < P; ++i)
        t2 *= B2;

    // 按列方向计算哈希值
    for (int j = 0; j + Q <= m; ++j)
    {
        ull e = 0;
        for (int i = 0; i < P; ++i)
            e = e * B2 + tmp[i][j];

        for (int i = 0; i + P <= n; ++i)
        {
            Hash[i][j] = e;
            if (i + P < n)
                e = e * B2 - t2 * tmp[i][j] + tmp[i + P][j];
        }
    }
}

int solve()
{
    // 将所有模式的哈希值放入multiset
    multiset<ull> unseen;
    for (int k = 0; k < T; ++k)
    {
        compute_hash(patterns[k], P, Q);
        unseen.insert(Hash[0][0]);
    }

    // 将出现的哈希值从multiset中删除
    compute_hash(field, N, M);
    for (int i = 0; i + P <= N; ++i)
        for (int j = 0; j + Q <= M; ++j)
            unseen.erase(Hash[i][j]);

    // 通过相减得到出现的模式的个数
    int ans = T - unseen.size();
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    while (cin >> N >> M >> T >> P >> Q && N)
    {
        for (int i = 0; i < N; ++i)
            cin >> field[i];
        for (int i = 0; i < T; ++i)
            for (int j = 0; j < P; ++j)
                cin >> patterns[i][j];
        int ans = solve();
        cout << "Case " << ++cnt << ": " << ans << "\n";
    }
    cout.flush();
    return 0;
}