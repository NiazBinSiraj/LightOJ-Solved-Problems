#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 0.00000001
#define pi 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define MS(XX,YY) memset(XX,YY,sizeof(XX))
#define runtime printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

ll prime[1000000];
bool mark[1000010];
ll nprime=0;
void sieve(int n)
{
    ll i,j,limit = sqrt(n)+2;

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

ll gcd(ll a, ll b)
{
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

ll ipow(ll base, ll exp)
{
    ll result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

bool IsPrime(ll number)
{
    if(number<2)
        return 0;
    if(number==2)
        return 1;
    if(number%2==0)
        return 0;
    for(int i=3;i<=sqrt(number);i += 2)
    {
        if(number%i==0)
            return 0;
    }
    return 1;
}


int main()
{
    int tc, cn=0;
    ll a,b,L,L1,c,p1,p;
    //Fin;
    //Fout;
    sieve(1000000);
    scanf("%lld",&tc);
    while(tc--)
    {
        c = 1;
        scanf("%lld%lld%lld",&a,&b,&L);
        L1 = (a*b)/gcd(a,b);

        if (L==L1) printf("Case %d: 1\n",++cn);
        else if(L%L1 != 0) printf("Case %d: impossible\n",++cn);
        else
        {

            for(int i=1;prime[i]*prime[i] <= L;i++)
            {
                p=0;
                p1=0;

                while(L%prime[i] == 0)
                {
                    L = L/prime[i];
                    p++;
                }

                while(L1%prime[i] == 0)
                {
                    L1 = L1/prime[i];
                    p1++;
                }
                if(p>p1) c = c*ipow(prime[i],p);
                //if((L==1 && L1==1) || (IsPrime(L)==1 && IsPrime(L1)==1) || (L==1 && IsPrime(L1)==1) || (IsPrime(L)==1 && L1==1)) break;
            }
            if(L1%L != 0) c = c*L;
            printf("Case %d: %lld\n",++cn,c);
        }
    }
   // runtime;
    return 0;
}
