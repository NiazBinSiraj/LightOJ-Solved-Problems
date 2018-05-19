#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 0.00000001
#define pi 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define MS(XX,YY) memset(XX,YY,sizeof(XX))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
int prime[1000010];
bool mark[10000010];
int nprime;

void sieve(int n)
{
    int i,j,limit = sqrt(n)+2;

    mark[1] = 1;

    for(i=4;i<=n;i+=2) mark[i]=1;
    prime[++nprime]=2;
    for(i=3;i<=n;i++)
    {
        if(!mark[i])
        {
            prime[++nprime]=i;

            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}


int main()
{
    int tc, cn=0;
    int n,cnt;
    sieve(10000000);
    //cout <<nprime<<endl;
    cin >> tc;
    //cout <<nprime<<endl;
    while(tc--)
    {
        cnt=0;
        cin >> n;

        for(int i=1;prime[i]<=(n/2);i++)
        {
            if(mark[n-prime[i]]==0) cnt++;

        }
        printf("Case %d: %d\n",++cn,cnt);
    }
    return 0;
}
