#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define MOD 1000000007
#define ck(XX) cout<<XX<<endl
#define set(XX,POS) XX|(1<<POS)
#define reset(XX,POS) XX&(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
LL prime[700000];
bool mark[10000110];
LL nprime=0;

void sieve(LL n)
{
    LL i,j,limit = sqrt(n)+2;

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
LL NOOD(LL n)
{
    if(n==1) return 1;
    LL s = sqrt(n)+2,res=1,cnt=0;
    LL i = 2;
    while(prime[i]<=s)
    {
        if(n%2 == 0)
        {
            n=n/2;
        }

        else if(n%prime[i]==0)
        {
            n=n/prime[i];
            cnt++;
            if(n==1) {res=res*(cnt+1);break;}
        }
        else
        {
            i++;
            res=res*(cnt+1);
            cnt=0;
        }
    }
    if(n != 1) res=res*2;
    return res;
}


int main()
{
    sieve(10000090LL);
    int tc,cn=0;
    LL n;
    cin >> tc;
    while(tc--)
    {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",++cn,NOOD(n)-1);
    }
    return 0;
}

