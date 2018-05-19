#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define MOD 1000000007LL
#define pii pair<LL,LL>
#define ck(XX) cout<<XX<<endl
#define Set(XX,POS) XX|(1<<POS)
#define reset(XX,POS) XX&(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define valid(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
LL prime[300005];
bool mark[300100];
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
    return;
}


LL bigmod(LL a, LL b, LL m)
{
LL res = 1;
    while(b)
    {
        if(b & 1)
        {
            res = ( (res % m) * (a % m) ) %m ;
        }
        a= ((a%m) * (a%m)) %m;
        b >>= 1;
    }
    return res;
}


pii extnuc(LL a,LL b)
{
    if(b==0)return pii(1,0);
    pii d=extnuc(b,a%b);
    return pii(d.second,d.first-d.second*(a/b));
}

LL ModInverse(LL n, LL m)
{
    pii d=extnuc(n,m);
    return ((d.first%m)+m)%m;
}


LL SOD(LL n, LL m)
{
    LL s = sqrt(n),res=1,cnt;
    LL i = 1;
    while(prime[i]<=s)
    {
        if(n%prime[i]==0)
        {
            cnt = 0;
            while(n%prime[i] == 0)
            {
                n=n/prime[i];
                cnt++;
            }
            s = sqrt(n);
            res = ((res%MOD)*(((bigmod(prime[i],cnt*m+1,MOD)-1+MOD)%MOD * (ModInverse(prime[i]-1,MOD)+MOD)%MOD)%MOD))%MOD;
        }
        i++;
    }

    if(n > 1) res = ((res%MOD)*((bigmod(n,m+1,MOD)-1+MOD)%MOD * (ModInverse(n-1,MOD)+MOD)%MOD)%MOD)%MOD;

    return res%MOD;
}



int main()
{
    //FAST
    //Fin;
    //Fout;
    sieve(300000LL);

    LL tc, cn=0 ,n ,m;
    LL ans;

    scanf("%lld",&tc);

    while(tc--)
    {
        scanf("%lld%lld",&n,&m);

        if(m==0) {printf("Case %lld: 1\n", ++cn); continue;}

        ans = SOD(n,m);

        printf("Case %lld: %lld\n", ++cn, ans);
    }
    return 0;
}
