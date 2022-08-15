// 特指整数保序离散化

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;  // n + 2m

int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;  // 三个 vector

int find(int x) {  // 二分找到 alls 中 >= x 的最小的数（区间向左侧缩小）
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;  // 为了和前缀和使用的坐标相同，所以是映射到一个从一开始的数组
}

// vector<int>::iterator unique(vector<int> &a) {  // 去重函数
//     int j = 0;
//     for (int i = 0; i < a.size(); i++)
//         if (!i || a[i] != a[i - 1]) a[j++] = a[i];
//     // a[0] ~ a[j - 1] 所有a中不重复的数

//     return a.begin() + j;
// }

int main() {
    cin >> n >> m;
    // n 次操作， m 次询问
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});

        alls.push_back(x);  // 加到待离散化的数组中
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        alls.push_back(l);  // 区间的左右端点需要离散化
        alls.push_back(r);
    }

    // 排序去重 （一般是映射下标，而下标不能重复）
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    // alls.erase(unique(alls), alls.end());

    // 处理插入
    for (auto item : add) {
        int x = find(item.first);
        a[x] += item.second;  // 注意处理插入数据的时候，要用加等于而不是等于
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    // 处理询问
    for (auto item : query) {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}

// https://www.acwing.com/activity/content/code/content/1415619/