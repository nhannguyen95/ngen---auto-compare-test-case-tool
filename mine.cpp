#include <stdio.h>

const int MAX_N = 10000 + 5;

int n, k, res;
int a[MAX_N], f[MAX_N];

void input()
{
    scanf("%d %d", &n, &k );
    for( int i = 1; i <= n; i++ )
        scanf("%d", a + i );
}

int max( int a, int b ) {
    return ( a > b ) ? a : b;
}

void solve()
{
    f[0] = 0;
    f[1] = a[1];
    res = max(0,a[1]);;
    for( int i = 1; i <= n; i++ ) {
        f[i] = -1e9;
        for( int j = 1; j <= k; j++ )
            if ( i - j >= 0 )
                f[i] = max( f[i], f[i-j] + a[i] );
        
        res = max( res, f[i] );
    }
}

void output() {
    printf("%d", res );
}

int main() {
    input();
    solve();
    output();
    
    return 0;
}
