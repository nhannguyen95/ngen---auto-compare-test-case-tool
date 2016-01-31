#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 10005;

int f[MAXN], n, k, res;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        f[i] = -(int)(1E7);
        for (int j = i - 1; j >= 0 && j >= i - k; --j)
            f[i] = max(f[i], x + f[j]);
        res = max(res, f[i]);
    }
    printf("%d", res);
}
