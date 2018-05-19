#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
int a[30][6], dp[30][6];
int n;

int f(int i, int j)
{
    if(i == n-1) return a[i][j];

    else if(dp[i][j]==0)
    {
        if(j==0)
            dp[i][j] = a[i][j] + min(f(i+1,j+1), f(i+1,j+2));

        else if(j==1)
            dp[i][j] = a[i][j] + min(f(i+1,j-1), f(i+1,j+1));

        else if(j==2)
            dp[i][j] = a[i][j] + min(f(i+1,j-1), f(i+1,j-2));
    }

    return dp[i][j];
}


int main()
{
    int tc, cn=0;
    int i,j;
    cin >> tc;
    while(tc--)
    {
        MS(a,0);
        MS(dp,0);
        scanf("%d",&n);

        for(i=0;i<n;i++)
            for(j=0;j<3;j++)
                scanf("%d",&a[i][j]);

        printf("Case %d: %d\n",++cn, min(f(0,0),min(f(0,1),f(0,2))));
    }
    return 0;
}
