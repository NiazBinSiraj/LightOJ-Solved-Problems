#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define db(XX) cout<<XX<<endl;
#define Fin freopen("input.txt","r",stdin);
#define Fout freopen("output.txt","w",stdout);
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY));
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0));
int dp[5][1010], a[1010];
int n;

int f(int i, int j)
{
    if(j>n-4+i || (i==2 && j==0))
        dp[i][j] = a[j];

    else if(dp[i][j]==0 && j==n-4+i)
        dp[i][j] = a[j] + f(i,(j+2)%n);

    else if(dp[i][j]==0 && j==n-5+i)
        dp[i][j] = a[j] + max(f(i,(j+2)%n),f(i,(j+3)%n));

    else if(dp[i][j]==0)
        dp[i][j] = a[j] + max(f(i,(j+2)%n),max(f(i,(j+3)%n),f(i,(j+4)%n)));

    return dp[i][j];
}


int main()
{
    int tc, cn=0,i,j;
    cin >> tc;
    while(tc--)
    {
        MS(dp,0);
        MS(a,0);

        cin>>n;

        for(i=0;i<n;i++)
            cin>>a[i];

        printf("Case %d: %d\n",++cn,max(f(0,0),max(f(1,1),f(2,2))));
    }
    return 0;
}
