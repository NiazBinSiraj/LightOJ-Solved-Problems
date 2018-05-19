#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define ck(XX) cout<<XX<<endl
#define Set(X,POS) X|(1<<POS) //For Bitwise Operation
#define reset(X,POS) X&(~(1<<POS)) //For Bitwise Operation
#define check(X,POS) (bool)(X&(1<<POS)) //For Bitwise Operation
#define toggle(X,POS) (X^(1<<POS)) //For Bitwise Operation
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
int dp[(1<<16)+3][25];
int a[20][20];
int n;

int f(int mask, int pos)
{
    if(mask == (1<<n)-1) return 0;
    if(dp[mask][pos] != 0) return dp[mask][pos];

    int ans = -1;

    for(int i=0; i<n; i++)
    {
        if(check(mask,i)==0)
        {
            int s=a[pos][i];
            s=s+f(Set(mask,i),pos+1);
            ans = max(ans,s);
        }
    }
    return dp[mask][pos] = ans;
}




int main()
{
    int tc, cn=0;
    scanf("%d",&tc);

    while(tc--)
    {
        MS(a,0);
        MS(dp,0);
        scanf("%d",&n);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);

        printf("Case %d: %d\n",++cn, f(0,0));
    }

    return 0;
}
