#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
LL dp[50][1000];

LL f(LL n, LL k)
{
    if(k==1)
        dp[n][k] = n*n;

    if(k==0)
        dp[n][k] = 1;

    else if(dp[n][k]==0)
    {
        if(f(n,k-1)%k == 0)
            dp[n][k] = ((f(n,k-1)/k)*f(n+1-k,1));

        else
            dp[n][k] = (f(n,k-1)*(f(n+1-k,1)/k));
    }
    return dp[n][k];
}


int main()
{
    int tc, cn=0;
    LL n,k;
    cin >> tc;
    while(tc--)
    {
        MS(dp,0);
        cin >>n>>k;
        if(k>n) printf("Case %d: 0\n",++cn);
        else printf("Case %d: %lld\n",++cn,f(n,k));
    }
    return 0;
}
