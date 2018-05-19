#include <bits/stdc++.h>
using namespace std;
#define M 10000007

long long a, b, c, d, e, f, dp[100000];
long long fn( long long n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if( dp[n]!=-1 ) return dp[n];
    else
    {
        dp[n] = ( fn(n-1)%M + fn(n-2)%M + fn(n-3)%M + fn(n-4)%M + fn(n-5)%M + fn(n-6)%M)%M;
        return dp[n];
    }
}
int main() {
    long long n, caseno = 0, cases;
    freopen("output.txt","w",stdout);

    scanf("%lld", &cases);
    while( cases-- ) {
             for(long long i=0;i<100000;i++)dp[i]=-1;
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, fn(n)%M);
    }
    return 0;
}
