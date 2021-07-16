#include <string.h>

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;

int cnt;
int h[N];   //堆
int ph[N];  //存放第k个插入点在堆中的下标
int hp[N];  //存放堆中点的插入次序（即堆中某点是第几个插入的点）

void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);  //
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);  // 交换堆中的两个点
}

void down(int u) {
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u) {
    while (u / 2 && h[u] < h[u / 2]) {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main() {
    int n, m = 0;
    scanf("%d", &n);
    while (n--) {
        char op[5];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I")) {
            scanf("%d", &x);
            cnt++;
            m++;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        } else if (!strcmp(op, "PM"))
            printf("%d\n", h[1]);
        else if (!strcmp(op, "DM")) {
            heap_swap(1, cnt);
            cnt--;
            down(1);
        } else if (!strcmp(op, "D")) {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, cnt);
            cnt--;
            up(k);
            down(k);
        } else {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;
}

// https://www.acwing.com/activity/content/code/content/1466871/