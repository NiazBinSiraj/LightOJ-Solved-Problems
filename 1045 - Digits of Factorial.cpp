#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 0.00000001
#define pi 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define runtime printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
double dp[1000015],b[1010];

int main()
{
    int tc, cn=0, n, base;
    ll digit;
    double s = 0;

    for(int i=1;i<=1000000;i++)
    {
        s = s+log10(i);
        dp[i] = s;
        if(i>=2 && i<=1000) b[i] = log10(i);
    }

    scanf("%d",&tc);

    while(tc--)
    {
        digit = 0;
        scanf("%d%d",&n,&base);
        digit = dp[n]/b[base];
        printf("Case %d: %lld\n",++cn,digit+1);
    }
    return 0;
}
