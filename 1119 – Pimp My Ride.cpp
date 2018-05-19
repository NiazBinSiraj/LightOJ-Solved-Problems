#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define ck(XX) cout<<XX<<endl
#define set(X,POS) X|(1<<POS) //For Bitwise Operation
#define reset(X,POS) X&(~(1<<POS)) //For Bitwise Operation
#define check(X,POS) (bool)(X&(1<<POS)) //For Bitwise Operation
#define toggle(X,POS) (X^(1<<POS)) //For Bitwise Operation
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

int dp[1<<15 + 2],a[20][20];
int n;

int f(int mask)
{
    int i,j,ret,ans,price;
    if(mask == (1<<n)-1) return 0;

    else if(dp[mask] != 0) return dp[mask];

        ans = 1<<28;

        for(i=0;i<n;i++)
        {
            if(check(mask,i)==0){
            price = a[i][i];
            for(j=0; j<n; j++)
            {
                if(i != j && check(mask,j)!=0) price = price+a[i][j];
            }
            ret = price+f(set(mask,i));
            ans = min(ans,ret);
            }
        }
    return dp[mask] = ans;
}




int main()
{
    int tc,cn=0;
    cin>>tc;

    while(tc--)
    {
        MS(dp,0);
        MS(a,0);
        cin >> n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cin >> a[i][j];

        printf("Case %d: %d\n",++cn,f(0));
    }
    return 0;
}
