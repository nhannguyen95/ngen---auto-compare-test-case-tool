#include <cstdio>
#include <random>
using namespace std;

const int maxn = 10005;
int a[maxn];

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis1(6, 12);
    uniform_int_distribution<> dis2(2, 4);
    uniform_int_distribution<> dis3(-12, 12);
    
    int n = dis1(gen);
    int k = dis2(gen);
    for(int i = 1; i <= n; i++ )
        a[i] = dis3(gen);
    
    printf("%d %d\n", n, k);
    for( int i = 1; i <= n; i++ )
        printf("%d ", a[i] );
    
    return 0;
}
