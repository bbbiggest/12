/*
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
*/

// ios::sync_with_stdio(false); // 在NOIP比赛中不要写.

// cout.flush() 和 cout<<flush 能清空缓冲区

//测试cin与scanf速度
//1. 向一个文件里输入1000000个随机数
///*
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
const int num = 1000000;
int main()
{
    ofstream file("data");
    for (int i = 0; i < num; i++)
    {
        file << rand() << ' ';
        if ((i + 1) % 20 == 0)
            file << endl;
    }
    return 0;
}
//*/

//2. 用cin读取这1000000个随机数
/*
#include <iostream>
#include <ctime>
#include <cstdio>
#include <windows.h>
using namespace std;
const int num = 1000000;
int main()
{
    freopen("data", "r", stdin);
    //ios::sync_with_stdio(false);
    int i, n, start, end;
    start = clock();
    for (i = 0; i < num - 2; i++)
        cin >> n;
    end = clock();
    cout << double(end - start) / CLOCKS_PER_SEC << endl;
    Sleep(5000);
    system("pause");
    return 0;
}
*/

//3. 用scanf读取这1000000个数
/*
#include <ctime>
#include <cstdio>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
using namespace std;
const int num = 1000000;
int main()
{
    freopen("data", "r", stdin);
    int i, n, start, end;
    start = clock();
    for (i = 0; i < num; i++)
        scanf("%d", &n);
    end = clock();
    //cout<<double(end-start)/CLOCKS_PER_SEC<<endl;
    printf("%f\n", double(end - start) / CLOCKS_PER_SEC);
    system("pause");
    Sleep(5000);
    return 0;
}
*/


/*
比较合理的解释：默认情况，cin与stdin总是保持同步的，
也就是说这两种方法可以混用，而不必担心文件指针混乱，
同时cout和stdout也一样，两者混用不会输 出顺序错乱。
正因为这个兼容性的特性，导致cin有许多额外的开销，如何禁用这个特性呢？
只需一个语句 std::ios::sync_with_stdio(false);，
这样就可以取消cin于stdin的同步了，此时的cin就与scanf差不多了。
另一种解释： cout在输出时总是要先将输出的存入缓存区。
而printf直接调用系统进行IO，它是非缓存的。
所以cout比printf慢。

好处：将cin cout速度提升至与scanf相差无几。
副作用：不能scanf cin之类的混用了。

1. C++为了让cin cout和scanf printf 同时使用时不产生混乱，
所以c++用一个缓冲区来同步c的标准流，
而std::ios::sync_with_stdio(false)可以关闭这一个同步，
让cin和cout不经过缓冲区；
2. tie()函数是把两个stream绑定到一起，flush()是把缓冲区的数据输出到文件，
而cin和cout是默认绑定在一起的，
每次使用都会调用flush()， 而cin.tie(nullptr)可以解除这个绑定；
cin和cout默认绑定在一起，是为了防止cin出现在cout之前，在绑定后，
每次cin都会先把缓冲区的数据刷新到输出文件中；
3. cin和cout默认绑定在一起，是为了防止cin出现在cout之前，在绑定后，
每次cin都会先把缓冲区的数据刷新到输出文件中；
*/
