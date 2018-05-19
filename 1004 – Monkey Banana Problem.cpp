#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
int a[210][110], dp[210][110];
int n;

int f(int i, int j)
{
    if(i==(2*n)-2 && j==0)
        return a[i][j];

    else if(i>n-2 && j==0 && dp[i][j]==0)
        dp[i][j]=a[i][j]+f(i+1,j);

    else if(i>n-2 && j==(2*n)-(i+2) && dp[i][j]==0)
        dp[i][j]=a[i][j]+f(i+1,j-1);

    else if(i>n-2 && dp[i][j]==0)
        dp[i][j]=a[i][j]+max(f(i+1,j-1),f(i+1,j));

    else if(dp[i][j]==0)
        dp[i][j]=a[i][j]+max(f(i+1,j),f(i+1,j+1));

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
        cin >> n;
        for(i=0;i<=n-1;i++)
        {
            for(j=0;j<=i;j++)
            {
                cin >> a[i][j];
            }
        }
        for(i=n; i<= (2*n)-2 ; i++)
        {
            for(j=0;j<(2*n)-(i+1);j++)
            {
                cin >> a[i][j];
            }
        }
        printf("Case %d: %d\n",++cn,f(0,0));
    }
    return 0;
}
